/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:32:50 by mypark            #+#    #+#             */
/*   Updated: 2022/04/22 08:22:54 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constant.h"
#include "error.h"
#include "expander.h"
#include "info.h"
#include "lexer.h"
#include "parsing.h"

static void	make_parsetree_node(t_parsetree_node *node)
{
	if (node == FT_NULL || node->tokens == FT_NULL)
		return ;
	if (is_edge_parentheses(node))
		remove_edge_parentheses(node);
	if (parse_bool(node) || parse_pipe(node))
	{
		make_parsetree_node(node->right);
		make_parsetree_node(node->left);
	}
	else if (parse_redir(node))
		make_parsetree_node(node->left);
	else if (is_edge_parentheses(node))
		make_parsetree_node(node);
}

t_parsetree_node	*parser(char *input, t_exe_info *info)
{
	t_parsetree_node	*head;
	t_tokens			*tks;

	tks = new_tokens();
	tokenizer(tks, input);
	free(input);
	if (syntax_error_check(tks))
	{
		free_tokens(tks);
		info->last_exit = 258;
		return (FT_NULL);
	}
	head = new_parsetree_node(tks, FT_NULL);
	make_parsetree_node(head);
	expander(head, info);
	return (head);
}
