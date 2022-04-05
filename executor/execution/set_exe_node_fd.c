/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_exe_node_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 21:54:48 by mypark            #+#    #+#             */
/*   Updated: 2022/04/05 15:54:27 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe_tree.h"

void	set_exe_node_fd(t_exetree_node *exe_node, int *parent_fd)
{
	if (exe_node->fd[0] == 0)
		exe_node->fd[0] = parent_fd[0];
	if (exe_node->fd[1] == 1)
		exe_node->fd[1] = parent_fd[1];
}