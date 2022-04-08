/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:55:44 by mypark            #+#    #+#             */
/*   Updated: 2022/04/08 16:22:43 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_tree.h"
#include "strict.h"

enum e_parsetree_node	to_enum_parsetree_node(enum e_token tk_type)
{
	if (tk_type == TK_IRD)
		return (NODE_IRD);
	if (tk_type == TK_ORD)
		return (NODE_ORD);
	if (tk_type == TK_HRD)
		return (NODE_HRD);
	if (tk_type == TK_ARD)
		return (NODE_ARD);
	if (tk_type == TK_PIPE)
		return (NODE_PIPE);
	if (tk_type == TK_AND)
		return (NODE_AND);
	if (tk_type == TK_OR)
		return (NODE_OR);
	return (TOKENS);
}

t_parsetree_node	*new_parsetree_node(t_tokens *tks, t_parsetree_node *parent)
{
	t_parsetree_node	*new;
	t_token				*tk;

	if (tks == NULL)
		return (NULL);
	new = strict_malloc(sizeof(t_parsetree_node), 1);
	new->left = NULL;
	new->right = NULL;
	new->parent = parent;
	new->tokens = tks;
	new->type = TOKENS;
	if (tks->head)
	{
		tk = tks->head->content;
		new->type = to_enum_parsetree_node(tk->type);
	}
	return (new);
}

void	free_parsetree_node(t_parsetree_node *node)
{
	free_tokens(node->tokens);
	free(node);
}

void	free_parsetree(t_parsetree_node *node)
{
	if (node == NULL)
		return ;
	free_parsetree(node->left);
	free_parsetree(node->right);
	node->left = NULL;
	node->right = NULL;
	free_parsetree_node(node);
}
