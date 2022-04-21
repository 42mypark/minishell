/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_redir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 02:02:09 by mypark            #+#    #+#             */
/*   Updated: 2022/04/22 08:24:33 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "constant.h"
#include "execution.h"
#include "fdctrl.h"
#include "strict.h"
#include "utils.h"
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

static int	exe_cmd(t_exetree_node *exnode, t_exe_info *info)
{
	pid_t	pid;
	int		ws;

	if (exnode->parent && exnode->parent->type == EXE_PIPE)
		pid = 0;
	else
		pid = strict_fork();
	if (pid)
	{
		strict_waitpid(pid, &ws, 0);
		restore_std_fd(info);
		return (calc_exit_status(ws));
	}
	else
	{
		signal(SIGQUIT, SIG_DFL);
		signal(SIGINT, SIG_DFL);
		strict_close(info->std_in);
		strict_close(info->std_out);
		strict_execve(exnode->cmd->cmd, exnode->cmd->args, *exnode->cmd->envp);
	}
	return (0);
}

static int	exe_builtin(t_exetree_node *exnode, t_exe_info *info)
{
	t_cmd_info	*cmd;
	int			exit_status;

	exit_status = 0;
	cmd = exnode->cmd;
	if (cmd == FT_NULL)
		return (0);
	else if (is_same(cmd->cmd, "echo"))
		exit_status = builtin_echo(exnode);
	else if (is_same(cmd->cmd, "export"))
		exit_status = builtin_export(exnode, info);
	else if (is_same(cmd->cmd, "env"))
		exit_status = builtin_env(exnode, info);
	else if (is_same(cmd->cmd, "cd"))
		exit_status = builtin_cd(exnode, info);
	else if (is_same(cmd->cmd, "pwd"))
		exit_status = builtin_pwd();
	else if (is_same(cmd->cmd, "unset"))
		exit_status = builtin_unset(exnode, info);
	else if (is_same(cmd->cmd, "exit"))
		exit_status = builtin_exit(exnode, info);
	restore_std_fd(info);
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
		if (exnode->cmd == FT_NULL || is_builtin(exnode->cmd->cmd))
			return (exe_builtin(exnode, info));
		return (exe_cmd(exnode, info));
	}
	return (0);
}
