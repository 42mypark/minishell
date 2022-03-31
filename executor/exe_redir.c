/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_redir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 02:02:09 by mypark            #+#    #+#             */
/*   Updated: 2022/04/01 02:45:25 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe_tree.h"
#include "info.h"
#include "executor.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void	exe_redir(t_exetree_node *exe_node, int parent_infd, int parent_outfd, t_exe_info *info)
{
	if (exe_node->infd == 0)
		exe_node->infd = parent_infd;
	if (exe_node->outfd == 1)
		exe_node->outfd = parent_outfd;
	strict_dup2(exe_node->infd, 0);
	strict_dup2(exe_node->outfd, 1);
	close_pipes(info->pipes);
	free_exe_info(info);
	//tree free???
	execve(exe_node->cmd->cmd, exe_node->cmd->args, exe_node->cmd->envp); //?
}
