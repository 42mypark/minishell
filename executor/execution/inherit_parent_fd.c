/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inherit_parent_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 21:54:48 by mypark            #+#    #+#             */
/*   Updated: 2022/04/05 15:54:27 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe_tree.h"
#include "strict.h"
#include "test.h"

void	inherit_parent_fd(t_exetree_node *exnode, int *parent_fd)
{
	int cnt = 0;
	if (exnode->fd[0] == 0)
		exnode->fd[0] = parent_fd[0];
	else if (exnode->parent && parent_fd[0] != exnode->parent->fd[0])
	{
		printf("hey1\n");
		strict_close(parent_fd[0]);
	}
	if (exnode->fd[1] == 1)
		exnode->fd[1] = parent_fd[1];
	else if (exnode->parent && parent_fd[1] != exnode->parent->fd[1])
	{
		printf("hey\n");
		strict_close(parent_fd[1]);
	}
	print_exetree_node(exnode, &cnt);
}
