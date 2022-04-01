/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:32:50 by mypark            #+#    #+#             */
/*   Updated: 2022/04/01 22:38:04 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_utils.h"
#include "error.h"
#include "test.h"

static void	parse_node(t_parsetree_node *node)
{
	if (node == NULL || node->tokens == NULL)
		return ;
	if (is_edge_parentheses(node))
		remove_edge_parenthesis(node);
	if (parse_bool(node) || parse_pipe(node))
	{
		parse_node(node->right);
		parse_node(node->left);
	}
	else if (parse_redir(node))
		parse_node(node->left);//?
	if (is_edge_parentheses(node))
		parse_node(node);
}

t_parsetree_node	*parse_script(t_tokens	*tks)
{
	t_parsetree_node	*head;

	head = new_parsetree_node(tks, NULL);
	parse_node(head);
	return (head);
}
