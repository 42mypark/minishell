/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_redir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 02:02:09 by mypark            #+#    #+#             */
/*   Updated: 2022/04/05 22:20:47 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe_tree.h"
#include "info.h"
#include "executor.h"
#include "strict.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include "test.h"
#include "builtin.h"

static int	exe_cmd(t_exetree_node *exe_node, t_exe_info *info)
{
	pid_t	pid;
	int		ws;

	pid = strict_fork();
	if (pid)
	{
		strict_waitpid(pid, &ws, 0);
		close_fd(exe_node->fd);
		return (calc_exit_status(ws));
	}
	else
	{
		strict_dup2(exe_node->fd[0], 0);
		strict_dup2(exe_node->fd[1], 1);
		close_pipes(info);
		strict_execve(exe_node->cmd->cmd, exe_node->cmd->args, exe_node->cmd->envp);
	}
	return (0);
}


int	exe_redir(t_exetree_node *exe_node, int *parent_fd, t_exe_info *info)
{
	signal(SIGINT, SIG_DFL);
	set_exe_node_fd(exe_node, parent_fd);
	close_pipe_oneside(exe_node->parent, exe_node, info);
	if (exe_node->left)
		execute_node(exe_node->left, exe_node->fd, info);
	else
	{
		if (exe_node->cmd == NULL)
		{
			close_fd(exe_node->fd);
			return (0);
		}
		if (exe_node->parent && exe_node->parent->type == EXE_PIPE)
		{
			if (is_builtin(exe_node->cmd->cmd))
				exit(exe_builtin(exe_node->cmd));
			exit(exe_cmd(exe_node, info));
		}
		else
		{
			if (is_builtin(exe_node->cmd->cmd))
				return (exe_builtin(exe_node->cmd));
			return (exe_cmd(exe_node, info));
		}
	}
	return (0);
}
