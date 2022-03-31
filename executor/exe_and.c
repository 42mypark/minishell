/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_and.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 23:46:16 by mypark            #+#    #+#             */
/*   Updated: 2022/04/01 02:49:21 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe_tree.h"
#include "info.h"
#include "executor.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void	exe_and(t_exetree_node *exe_node, int parent_infd, int parent_outfd, t_exe_info *info)
{
	pid_t	pid;

	if (exe_node->infd == 0)
		exe_node->infd = parent_infd;
	if (exe_node->outfd == 1)
		exe_node->outfd = parent_outfd;
	pid = strict_fork();
	if (pid)
	{
		insert_new_pid(info, pid);
		return ;
	}
	if (exe_bool_child(exe_node->left, exe_node->infd, exe_node->outfd, info) == 0)
		return ;
	exe_bool_child(exe_node->right, exe_node->infd, exe_node->outfd, info);
}
