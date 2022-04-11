/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:07:41 by mypark            #+#    #+#             */
/*   Updated: 2022/04/12 03:39:24 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "exe_tree.h"
#include "executor.h"
#include "utils.h"
#include "constant.h"
#include <errno.h>
#include <unistd.h>
#include <string.h>

static int	change_pwd(char *dir, char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp("PWD", envp[i], 3) == 0)
		{
			free(envp[i]);
			envp[i] = ft_strjoin("PWD=", dir);
			if (envp[i] == FT_NULL)
				print_malloc_error();
			return (1);
		}
		i++;
	}
	return (0);
}

static int	cd_no_arg(char **envp)
{
	char	*home;
	int		ret;

	home = dupenv("HOME", envp);
	ret = chdir(home);
	if (ret == -1)
	{
		print_strerror("cd", home, strerror(errno));
		free(home);
		return (1);
	}
	change_pwd(home, envp);
	free(home);
	return (0);
}

static int	cd_with_arg(char *dir, char **envp)
{
	int		ret;
	char	*new_dir;

	ret = chdir(dir);
	if (ret == -1)
	{
		print_strerror("cd", dir, strerror(errno));
		return (1);
	}
	new_dir = getcwd(FT_NULL, 0);
	if (new_dir == 0)
	{
		print_strerror("cd", new_dir, strerror(errno));
		free(new_dir);
		return (1);
	}
	change_pwd(new_dir, envp);
	free(new_dir);
	return (0);
}

int	builtin_cd(t_exetree_node *exnode, t_exe_info *info)
{
	char	*dir;

	dir = exnode->cmd->args[1];
	if (dir == FT_NULL)
		return (cd_no_arg(info->envp));
	else
		return (cd_with_arg(dir, info->envp));
}
