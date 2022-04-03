/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_and.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 23:46:16 by mypark            #+#    #+#             */
/*   Updated: 2022/04/04 01:28:25 by mypark           ###   ########.fr       */
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

void	exe_and(t_exetree_node *exe_node, int parent_infd, int parent_outfd, t_exe_info *info)
{
	int	exit_status;

	set_exe_node_fd(exe_node, parent_infd, parent_outfd);
	close_pipe_oneside(exe_node->parent, exe_node, info);
	exit_status = exe_bool_child(exe_node->left, exe_node->infd, exe_node->outfd, info);
	if (exit_status != 0)
		exit(exit_status);
	exit_status = exe_bool_child(exe_node->right, exe_node->infd, exe_node->outfd, info);
	if (exit_status != 0)
		exit(exit_status);
	exit(0);
}
