/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_redir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 02:02:09 by mypark            #+#    #+#             */
/*   Updated: 2022/04/03 03:08:22 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe_tree.h"
#include "info.h"
#include "executor.h"
#include "strict.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "test.h"

void	exe_redir(t_exetree_node *exe_node, int parent_infd, int parent_outfd, t_exe_info *info)
{
	set_exe_node_fd(exe_node, parent_infd, parent_outfd);
	close_pipe_oneside(exe_node->parent, exe_node, info);
	if (exe_node->left)
	{
		execute_node(exe_node->left, exe_node->infd, exe_node->outfd, info);
	}
	else
	{
		strict_dup2(exe_node->infd, 0);
		strict_dup2(exe_node->outfd, 1);
		close_pipes(info->pipes);
		free_exe_info(info);
		if (exe_node->cmd == NULL)
			exit(0);
		execve(exe_node->cmd->cmd, exe_node->cmd->args, exe_node->cmd->envp); //?
	}
}
