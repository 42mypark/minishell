/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_exe_node_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 21:54:48 by mypark            #+#    #+#             */
/*   Updated: 2022/04/01 21:54:56 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe_tree.h"

void	set_exe_node_fd(t_exetree_node *exe_node, int parent_infd, int parent_outfd)
{
	if (exe_node->infd == 0)
		exe_node->infd = parent_infd;
	if (exe_node->outfd == 1)
		exe_node->outfd = parent_outfd;
}