/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_and.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 23:46:16 by mypark            #+#    #+#             */
/*   Updated: 2022/04/22 08:25:02 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strict.h"
#include "fdctrl.h"
#include "execution.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int	exe_and(t_exetree_node *exnode, int *parent_fd, t_exe_info *info)
{
	int	exit_status;

	receive_parent_fd(exnode, parent_fd);
	close_unused_pipe(exnode, info);
	exit_status = execute_node(exnode->left, exnode->fd, info);
	if (exit_status == 0)
		exit_status = execute_node(exnode->right, exnode->fd, info);
	close_myinout_fd(exnode);
	return (exit_status);
}
