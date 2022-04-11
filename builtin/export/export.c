/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:07:41 by mypark            #+#    #+#             */
/*   Updated: 2022/04/12 03:39:24 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constant.h"
#include "error.h"
#include "exe_tree.h"
#include "export.h"
#include "strict.h"
#include <unistd.h>

int	is_valid_var(char *var)
{
	int	i;

	if (ft_isdigit(var[0]) || var[0] == '=')
		return (0);
	i = 0;
	while (var[i] && var[i] != '=')
	{
		if (!ft_isalnum(var[i]) && var[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

static int	already_exist(char *var, char **envp)
{
	int	i;
	int	eq;

	i = 0;
	eq = ft_strchri(var, '=');
	if (eq == -1)
		eq = ft_strlen(var);
	while (envp[i])
	{
		if (ft_strncmp(var, envp[i], eq) == 0)
		{
			if (var[eq])
			{
				free(envp[i]);
				envp[i] = ft_strdup(var);
			}
			return (1);
		}
		i++;
	}
	return (0);
}

static void	add_var(char *var, t_exe_info *info)
{
	char	**new_envp;
	int		wc;
	int		i;

	wc = ft_wordcount(info->envp) + 1;
	new_envp = strict_malloc(sizeof(char *), wc + 1);
	new_envp[wc] = FT_NULL;
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

static int	register_new_var(char **args, t_exe_info *info)
{
	int		ai;
	int		exit_status;

	exit_status = 0;
	ai = 0;
	while (args[++ai])
	{
		if (!is_valid_var(args[ai]))
		{
			print_strerror("export", args[ai], ERRMSG_EXPORT_NOVALID);
			exit_status = 1;
			continue ;
		}
		if (already_exist(args[ai], info->envp))
			continue ;
		add_var(args[ai], info);
	}
	return (exit_status);
}

int	builtin_export(t_exetree_node *exnode, t_exe_info *info)
{
	if (exnode->cmd->args[1])
		return (register_new_var(exnode->cmd->args, info));
	else
		export_print(info->envp);
	return (0);
}
