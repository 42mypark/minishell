/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_and.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 23:46:16 by mypark            #+#    #+#             */
/*   Updated: 2022/04/08 04:29:07 by mypark           ###   ########.fr       */
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

int	exe_and(t_exetree_node *exnode, int *parent_fd, t_exe_info *info)
{
	int	exit_status;

	inherit_parent_fd(exnode, parent_fd);
	close_unused_pipe(exnode, info);
	exit_status = execute_node(exnode->left, exnode->fd, info);
	if (exit_status == 0)
		exit_status = execute_node(exnode->right, exnode->fd, info);
	// if (exnode->parent && exnode->parent->type == EXE_PIPE)
	// 	exit(exit_status);
	close_inout_fd(exnode);
	return (exit_status);
}
