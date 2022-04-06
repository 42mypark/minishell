/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:07:41 by mypark            #+#    #+#             */
/*   Updated: 2022/04/07 03:14:46 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "error.h"
#include "exe_tree.h"
#include "executor.h"
#include "strict.h"
#include <errno.h>
#include <string.h>
#include "test.h"

static void	register_new_var(char *var, t_exe_info *info)
{
	int		count;
	char	**new_envp;
	int		i;

	count = ft_wordcount(info->envp) + 1;
	new_envp = strict_malloc(sizeof(char *), count + 1);
	i = 0;
	while (info->envp[i])
	{
		new_envp[i] = ft_strdup(info->envp[i]);
		i++;
	}
	new_envp[i] = ft_strdup(var);
	ft_splitfree(info->envp);
	info->envp = new_envp;
}

static int	is_all_checked(char *check, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (check[i] == 0)
			return (0);
		i++;
	}
	return (1);
}

static char	*get_ordered_var(char **envp, char *check)
{
	int	fast;
	int	i;

	i = -1;
	fast = -1;
	while (envp[++i])
	{
		if (fast == -1 && check[i] == 0)
			fast = i++;
		if (fast == -1)
			continue;
		if (check[i] == 0 && ft_strncmp(envp[i], envp[fast], -1) < 0)
			fast = i;
	}
	check[fast] = 1;
	return (envp[fast]);
}

static void	print_export(char **envp)
{
	int		i;
	int		eq;
	int		wc;
	char	*check;
	char	*var;

	wc = ft_wordcount(envp);
	check = strict_malloc(sizeof(char), wc);
	i = 0;
	while (i < wc)
		check[i++] = 0;
	while (!is_all_checked(check, wc))
	{
		var = get_ordered_var(envp, check);
		eq = ft_strchri(var, '=');
		ft_putstr_fd("declare -x ", 1);
		write(1, var, eq + 1);
		write(1, "\"", 1);
		if (var[eq + 1])
			ft_putstr_fd(var + eq + 1, 1);
		write(1, "\"\n", 2);
	}
	free(check);
}


int	builtin_export(t_exetree_node *exe_node, t_exe_info *info)
{
	int		count;
	int		i;
	char	*new_envp;
	// print_exetree_node(exe_node, &count);
	// print_exe_info(info);

	// handle more than 2 args error
	if (exe_node->cmd->args[1])
		register_new_var(exe_node->cmd->args[1], info);
	else
		print_export(info->envp);
	return (0);
}
