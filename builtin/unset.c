/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:07:41 by mypark            #+#    #+#             */
/*   Updated: 2022/04/07 16:10:14 by mypark           ###   ########.fr       */
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

static void	delete_var(t_exe_info *info, int del_i)
{
	int	wc;
	int	ei;
	int	ni;
	char	**new_envp;

	printf("im in\n");
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

int	builtin_unset(t_exetree_node *exe_node, t_exe_info *info)
{
	int		wc;
	int		eq;
	int		ai;
	int		ei;
	char	**args;

	// a number can't be the first of env_var name.

	args = exe_node->cmd->args;
	wc = ft_wordcount(args);
	if (wc == 1)
		return (0);
	ai = 1;
	while(ai < wc)
	{
		ei = 0;
		while (info->envp[ei])
		{
			eq = ft_strchri(info->envp[ei], '=');
			if (ft_strncmp(args[ai], info->envp[ei], eq) == 0)
				delete_var(info, ei);
			ei++;
		}
		ai++;
	}
	return (0);
}
