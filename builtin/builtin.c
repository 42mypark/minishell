/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:15:05 by mypark            #+#    #+#             */
/*   Updated: 2022/04/07 01:58:37 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "info.h"
#include "builtin.h"
#include "test.h"

int	is_builtin(char *cmd)
{
	static char	*builtins[] = { /*"echo", */\
							"cd", \
							"pwd", \
							"export", \
							"unset", \
							"env", \
							"exit",
							0
	};
	int			i;

	i = 0;
	while (builtins[i])
	{
		if(is_same(builtins[i], cmd))
			return (1);
		i++;
	}
	return (0);
}

int	exe_builtin(t_exetree_node *exe_node, t_exe_info *e_info)
{
	t_cmd_info	*cmd;

	cmd = exe_node->cmd;
	if (exe_node->cmd == NULL)
	{
		restore_inout_fd(exe_node);
		return (0);
	}
	if (is_same(cmd->cmd, "export"))
		return (builtin_export(exe_node, e_info));
	if (is_same(cmd->cmd, "cd"))
		return (builtin_cd(exe_node));
	if (is_same(cmd->cmd, "pwd"))
		return (builtin_pwd(exe_node));
	if (is_same(cmd->cmd, "exit"))
		builtin_exit(e_info);
	return (0);
}
