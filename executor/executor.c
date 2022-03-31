/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 22:11:07 by mypark            #+#    #+#             */
/*   Updated: 2022/03/31 22:33:54 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe_tree.h"

void	executor(t_exetree_node *exe_node, int parent_infd, int parent_outfd)
{
	int	p[2];

	if (exe_node->type == EXE_PIPE)
	{
		//pipe(p);
		// executor(exe_node->left, exe_node->infd, p[1]);
		// executor(exe_node->left, p[0], exe_node->outfd);
	}
}