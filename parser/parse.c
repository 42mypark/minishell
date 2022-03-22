/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:32:50 by mypark            #+#    #+#             */
/*   Updated: 2022/03/22 23:41:35 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_utils.h"
#include "error.h"
#include "test.h"

static void	parse_node(t_parsetree_node *node)
{
	if (node == NULL || node->parsed)
		return ;
	remove_parenthesis(node);
	if (parse_bool(node) || parse_pipe(node))
	{
		parse_node(node->right);
		parse_node(node->left);
	}
	else if (parse_redir(node))
	{
		parse_node(node->left);
	}
	node->parsed = 1;
}

t_parsetree_node	*parse_script(t_tokens	*tks)
{
	t_parsetree_node	*head;

	head = new_parsetree_node(tks, NULL);
	parse_node(head);
	return (head);
}
