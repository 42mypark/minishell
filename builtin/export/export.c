/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:07:41 by mypark            #+#    #+#             */
/*   Updated: 2022/04/08 02:32:42 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "exe_tree.h"
#include "strict.h"
#include "export.h"
#include "test.h"

static int	already_exist(char *var, char **envp)
{
	int	i;
	int	eq;

	i= 0;
	eq = ft_strchri(var, '=');
	while (envp[i])
	{
		if (ft_strncmp(var, envp[i], eq) == 0)
		{
			free(envp[i]);
			envp[i] = ft_strdup(var);
			return (1);
		}
		i++;
	}
	return (0);
}

static void	register_new_var(char *var, t_exe_info *info)
{
	int		count;
	char	**new_envp;
	int		i;

	if (already_exist(var, info->envp))
		return ;
	count = ft_wordcount(info->envp) + 1;
	new_envp = strict_malloc(sizeof(char *), count + 1);
	new_envp[count] = NULL;
	i = 0;
	while (info->envp[i])
	{
		new_envp[i] = ft_strdup(info->envp[i]);
		i++;
	}
	new_envp[i] = new_envp[i - 1];
	new_envp[i - 1] = ft_strdup(var);
	ft_splitfree(info->envp);
	info->envp = new_envp;
}

int	builtin_export(t_exetree_node *exe_node, t_exe_info *info)
{
	// print_exetree_node(exe_node, &count);
	// print_exe_info(info);

	// handle more than 2 args error
	if (exe_node->cmd->args[1])
		register_new_var(exe_node->cmd->args[1], info);
	else
		export_print(info->envp);
	return (0);
}
