/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:07:41 by mypark            #+#    #+#             */
/*   Updated: 2022/04/08 02:23:55 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "error.h"
#include "exe_tree.h"
#include "executor.h"
#include <errno.h>
#include <string.h>

int	builtin_cd(t_exetree_node *exnode)
{
	int		ret;
	char	*home;
	char	**envp;
	char	*dir;

	//PWD change

	envp = *exnode->cmd->envp;
	dir = exnode->cmd->args[1];
	if (dir == NULL)
	{
		home = dupenv("HOME", envp);
		ret = chdir(home);
		if (ret == -1)
		{
			print_strerror("builtin", strerror(errno));
			return (1);
		}
		free(home);
		return (0);
	}
	ret = chdir(dir);
	if (ret == -1)
	{
		print_strerror("builtin", strerror(errno));
		return (1);
	}
	return (0);
}
