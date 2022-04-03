/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_tree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 01:55:13 by mypark            #+#    #+#             */
/*   Updated: 2022/04/03 16:08:11 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe_tree.h"
#include "strict.h"
#include "error.h"

t_exetree_node	*new_exetree_node(t_exetree_node *parent, enum e_exetree_node type, int infd, int outfd)
{
	t_exetree_node	*node;

	node = strict_malloc(sizeof(t_exetree_node), 1);
	node->parent = parent;
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
	free_cmd_info(node->cmd);
	free_err_info(node->err);
	free(node);
}

void	free_exetree(t_exetree_node *node)
{
	if (node == NULL)
		return ;
	free_exetree(node->left);
	free_exetree(node->right);
	free_exetree_node(node);
}

