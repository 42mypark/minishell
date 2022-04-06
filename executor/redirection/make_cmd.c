/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 00:14:37 by mypark            #+#    #+#             */
/*   Updated: 2022/04/07 02:12:44 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe_tree.h"
#include "parse_tree.h"
#include "utils.h"
#include "test.h"
#include "builtin.h"
#include <fcntl.h>

static char	*can_access(char *cmd, char **paths)
{
	int		i;

	if (is_builtin(cmd) || access((const char *)cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	i = 0;
	while (paths[i])
	{
		paths[i] = ft_strappend(paths[i], "/");
		paths[i] = ft_strappend(paths[i], cmd);
		if (access((const char *)paths[i], X_OK) == 0)
			return (ft_strdup(paths[i]));
		i++;
	}
	return (0);
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
	cmd = can_access(args[0], paths);
	if (cmd != NULL)
		e_nd->cmd = new_cmd_info(cmd, args, &info->envp);
	else
	{
		e_nd->type = EXE_ERROR;
		e_nd->err = new_err_info("minishell : command not found", 127);
		ft_splitfree(args);
	}
	ft_splitfree(paths);
	free(env_path);
	return (1);
}
