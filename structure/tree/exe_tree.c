/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_tree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 01:55:13 by mypark            #+#    #+#             */
/*   Updated: 2022/04/12 03:39:50 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe_tree.h"
#include "strict.h"
#include "error.h"
#include "constant.h"

t_exetree_node	*new_exetree_node(\
	t_exetree_node *parent, \
	enum e_exetree_node type, \
	int infd, int outfd\
)
{
	t_exetree_node	*node;

	node = strict_malloc(sizeof(t_exetree_node), 1);
	node->parent = parent;
	node->type = type;
	node->left = 0;
	node->right = 0;
	node->fd = strict_malloc(sizeof(int), 2);
	node->fd[0] = infd;
	node->fd[1] = outfd;
	node->cmd = 0;
	node->err = 0;
	node->pipelines = 0;
	return (node);
}

void	free_exetree_node(t_exetree_node *node)
{
	free(node->fd);
	free_cmd_info(node->cmd);
	free_err_info(node->err);
	free(node);
}

void	free_exetree_pipelines(t_pipelines **pipelines)
{
	if (pipelines == FT_NULL)
		return ;
	ft_lstclear(pipelines, free_exetree);
}

void	free_exetree(void *node)
{
	t_exetree_node	*e_node;

	e_node = (t_exetree_node *)node;
	if (e_node == FT_NULL)
		return ;
	free_exetree(e_node->left);
	free_exetree(e_node->right);
	free_exetree_pipelines(&e_node->pipelines);
	free_exetree_node(e_node);
}
