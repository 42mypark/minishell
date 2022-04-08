/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_or.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 23:46:16 by mypark            #+#    #+#             */
/*   Updated: 2022/04/08 16:40:10 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe_tree.h"
#include "info.h"
#include "executor.h"
#include "strict.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int	exe_or(t_exetree_node *exnode, int *parent_fd, t_exe_info *info)
{
	int	exit_status;

	receive_parent_fd(exnode, parent_fd);
	close_unused_pipe(exnode, info);

	exit_status = execute_node(exnode->left, exnode->fd, info);
	if (exit_status != 0)
		exit_status = execute_node(exnode->right, exnode->fd, info);
	close_myinout_fd(exnode);
	return (exit_status);
}
