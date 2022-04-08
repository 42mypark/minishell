/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:07:41 by mypark            #+#    #+#             */
/*   Updated: 2022/04/09 04:11:43 by mypark           ###   ########.fr       */
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
#include "constant.h"
#include "export.h"

static void	replace_envp(t_exe_info *info, int del_i)
{
	int	wc;
	int	ei;
	int	ni;
	char	**new_envp;

	wc = ft_wordcount(info->envp);
	new_envp = strict_malloc(sizeof(char *), wc);
	new_envp[wc - 1] = NULL;
	ni = 0;
	ei = -1;
	while (info->envp[++ei])
	{
		if (ei == del_i)
			continue ;
		new_envp[ni++] = ft_strdup(info->envp[ei]);
	}
	ft_splitfree(info->envp);
	info->envp = new_envp;
}

static void	delete_var(char *var, t_exe_info *info)
{
	int	ei;
	int	eq;

	ei = 0;
	while (info->envp[ei])
	{
		eq = ft_strchri(info->envp[ei], '=');
		if (ft_strncmp(var, info->envp[ei], eq) == 0)
			replace_envp(info, ei);
		ei++;
	}
}

int	builtin_unset(t_exetree_node *exe_node, t_exe_info *info)
{
	int		wc;
	int		ai;
	int		exit_status;
	char	**args;

	exit_status = 0;
	args = exe_node->cmd->args;
	wc = ft_wordcount(args);
	if (wc == 1)
		return (exit_status);
	ai = 0;
	while(++ai < wc)
	{
		if (!is_valid_var(args[ai]))
		{
			print_strerror("unset", args[ai], ERRMSG_UNSET_NOVALID);
			exit_status = 1;
			continue;
		}
		delete_var(args[ai], info);
	}
	return (exit_status);
}
