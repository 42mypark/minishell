/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_inout_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 21:16:13 by mypark            #+#    #+#             */
/*   Updated: 2022/04/08 02:49:53 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe_tree.h"
#include "libft.h"
#include "strict.h"
#include "test.h"

void	close_inout_fd(t_exetree_node *exnode)
{
	t_exetree_node	*parent;

	parent = exnode->parent;
	printf("curr in out : %d %d\n", exnode->fd[0], exnode->fd[1]);
	if (parent)
		printf("parent in out : %d %d\n", parent->fd[0], parent->fd[1]);
	if (parent == NULL && exnode->fd[0] != 0)
		strict_close(exnode->fd[0]);
	if (parent == NULL && exnode->fd[1] != 1)
		strict_close(exnode->fd[1]);
	if (parent && parent->fd[0] != exnode->fd[0])
		strict_close(exnode->fd[0]);
	if (parent && parent->fd[1] != exnode->fd[1])
		strict_close(exnode->fd[1]);
}
