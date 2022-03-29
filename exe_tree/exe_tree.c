/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_tree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 01:55:13 by mypark            #+#    #+#             */
/*   Updated: 2022/03/30 02:13:38 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe_tree.h"
#include "error.h"

t_exetree_node	*new_exetree_node(enum e_exetree_node type, int infd, int outfd)
{
	t_exetree_node	*node;

	node = malloc(sizeof(t_exetree_node));
	if (node == 0)
		print_malloc_error();
	node->type = type;
	node->left = 0;
	node->right = 0;
	node->infd = infd;
	node->outfd = outfd;
	node->cmd = 0;
	node->err = 0;
	return (node);
}

void	free_exetree_node(t_exetree_node *node)
{
	free(node->cmd);
	free(node->err);
	free(node);
}
