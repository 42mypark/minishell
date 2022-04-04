/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */ 
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:32:50 by mypark            #+#    #+#             */
/*   Updated: 2022/04/02 01:18:19 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "expander.h"
#include "info.h"
#include "error.h"
#include "tokenizer.h"

static void	make_parsetree_node(t_parsetree_node *node)
{
	if (node == NULL || node->tokens == NULL)
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
		return (NULL);
	}
	head = new_parsetree_node(tks, NULL);
	make_parsetree_node(head);
	expander(head, info->envp);
	free_tokens(tks);
	return (head);
}
