/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_redir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 02:02:09 by mypark            #+#    #+#             */
/*   Updated: 2022/04/08 16:15:08 by mypark           ###   ########.fr       */
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

static int	exe_cmd(t_exetree_node *exnode)
{
	pid_t	pid;
	int		ws;

	pid = strict_fork();
	if (pid)
	{
		strict_waitpid(pid, &ws, 0);
		restore_std_fd();
		return (calc_exit_status(ws));
	}
	else
	{
		signal(SIGINT, SIG_DFL);
		strict_execve(exnode->cmd->cmd, exnode->cmd->args, *exnode->cmd->envp);
	}
	return (0);
}

static int	exe_builtin(t_exetree_node *exnode, t_exe_info *e_info)
{
	t_cmd_info	*cmd;
	int			exit_status;

	cmd = exnode->cmd;
	if (exnode->cmd == NULL)
		exit_status = 0;
	if (is_same(cmd->cmd, "echo"))
		exit_status = builtin_echo(exnode);
	if (is_same(cmd->cmd, "export"))
		exit_status = builtin_export(exnode, e_info);
	if (is_same(cmd->cmd, "env"))
		exit_status = builtin_env(e_info);
	if (is_same(cmd->cmd, "cd"))
		exit_status = builtin_cd(exnode);
	if (is_same(cmd->cmd, "pwd"))
		exit_status = builtin_pwd(exnode);
	if (is_same(cmd->cmd, "unset"))
		exit_status = builtin_unset(exnode, e_info);
	if (is_same(cmd->cmd, "exit"))
		builtin_exit(e_info);
	restore_std_fd();
	return (exit_status);
}

int	exe_redir(t_exetree_node *exnode, int *parent_fd, t_exe_info *info)
{
	int	exit_status;

	receive_parent_fd(exnode, parent_fd);
	close_unused_pipe(exnode, info);
	if (exnode->left)
	{
		exit_status = execute_node(exnode->left, exnode->fd, info);
		close_myinout_fd(exnode);
		return (exit_status);
	}
	else
	{
		strict_dup2(exnode->fd[0], 0);
		strict_dup2(exnode->fd[1], 1);
		close_myinout_fd(exnode);
		if (exnode->cmd == NULL || is_builtin(exnode->cmd->cmd))
			return (exe_builtin(exnode, info));
		return (exe_cmd(exnode));
	}
	return (0);
}
