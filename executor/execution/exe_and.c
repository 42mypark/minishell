/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_and.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 23:46:16 by mypark            #+#    #+#             */
/*   Updated: 2022/04/05 18:44:30 by mypark           ###   ########.fr       */
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

int	exe_and(t_exetree_node *exe_node, int *parent_fd, t_exe_info *info)
{
	int	exit_status;

	set_exe_node_fd(exe_node, parent_fd);
	close_pipe_oneside(exe_node->parent, exe_node, info);

	exit_status = execute_node(exe_node->left, exe_node->fd, info);
	if (exit_status == 0)
		exit_status = execute_node(exe_node->right, exe_node->fd, info);
	if (exe_node->parent && exe_node->parent->type == EXE_PIPE)
		exit(exit_status);
	return (exit_status);
}
