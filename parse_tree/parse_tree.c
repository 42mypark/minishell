/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:55:44 by mypark            #+#    #+#             */
/*   Updated: 2022/03/25 21:09:17 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_tree.h"

enum e_parsetree_node	to_enum_parsetree_node(enum e_token tk_type)
{
	if (tk_type == IRD)
		return (NODE_IRD);
	if (tk_type == ORD)
		return (NODE_ORD);
	if (tk_type == HRD)
		return (NODE_HRD);
	if (tk_type == ARD)
		return (NODE_ARD);
	if (tk_type == PIPE)
		return (NODE_PIPE);
	if (tk_type == AND)
		return (NODE_AND);
	if (tk_type == OR)
		return (NODE_OR);
	return (TOKENS);
}

t_parsetree_node	*new_parsetree_node(t_tokens *tks, t_parsetree_node *parent)
{
	t_parsetree_node	*new;
	t_token				*tk;

	new = malloc(sizeof(t_parsetree_node));
	if (new == NULL || tks == NULL)
		return (NULL);
	new->left = NULL;
	new->right = NULL;
	new->parent = parent;
	new->tokens = tks;
	new->parsed = 0;
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
