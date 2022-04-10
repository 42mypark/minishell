/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 00:14:37 by mypark            #+#    #+#             */
/*   Updated: 2022/04/10 17:15:31 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe_tree.h"
#include "parse_tree.h"
#include "utils.h"
#include "constant.h"
#include "builtin.h"
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

static char	*find_cmd(char *cmd, char **paths)
{
	struct stat	file_status;
	int			i;

	if (is_builtin(cmd) || lstat(cmd, &file_status) == 0)
		return (ft_strdup(cmd));
	i = 0;
	while (paths[i])
	{
		paths[i] = ft_strappend(paths[i], "/");
		paths[i] = ft_strappend(paths[i], cmd);
		if (lstat(paths[i], &file_status) == 0)
			return (ft_strdup(paths[i]));
		i++;
	}
	return (NULL);
}

int	make_cmd(t_parsetree_node *p_nd, t_exetree_node *e_nd, t_exe_info *info)
{
	char	**args;
	char	**paths;
	char	*env_path;
	char	*cmd;

	args = tokens_to_splited(p_nd->tokens);
	env_path = dupenv("PATH", info->envp);
	paths = ft_split(env_path, ':');
	cmd = find_cmd(args[0], paths);
	if (cmd != NULL)
		e_nd->cmd = new_cmd_info(cmd, args, &info->envp);
	else
	{
		e_nd->type = EXE_ERROR;
		e_nd->err = new_err_info(strerror(errno), 127);
		ft_splitfree(args);
	}
	ft_splitfree(paths);
	free(env_path);
	return (1);
}
