/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_redir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 02:02:09 by mypark            #+#    #+#             */
/*   Updated: 2022/04/06 21:55:58 by mypark           ###   ########.fr       */
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

static int	exe_cmd(t_exetree_node *exe_node)
{
	pid_t	pid;
	int		ws;

	pid = strict_fork();
	if (pid)
	{
		strict_waitpid(pid, &ws, 0);
		restore_inout_fd(exe_node);
		return (calc_exit_status(ws));
	}
	else
	{
		signal(SIGINT, SIG_DFL);
		strict_execve(exe_node->cmd->cmd, exe_node->cmd->args, exe_node->cmd->envp);
	}
	return (0);
}


int	exe_redir(t_exetree_node *exe_node, int *parent_fd, t_exe_info *info)
{
	set_exe_node_fd(exe_node, parent_fd);
	close_pipe_oneside(exe_node->parent, exe_node, info);
	if (exe_node->left)
		execute_node(exe_node->left, exe_node->fd, info);
	else
	{
		strict_dup2(exe_node->fd[0], 0);
		strict_dup2(exe_node->fd[1], 1);
		close_fd(exe_node, info);
		close_pipes(info);
		if (exe_node->parent && exe_node->parent->type == EXE_PIPE)
		{
			if (exe_node->cmd == NULL || is_builtin(exe_node->cmd->cmd))
				exit(exe_builtin(exe_node, info));
			exit(exe_cmd(exe_node));
		}
		else
		{
			if (exe_node->cmd == NULL || is_builtin(exe_node->cmd->cmd))
				return (exe_builtin(exe_node, info));
			return (exe_cmd(exe_node));
		}
	}
	return (0);
}
