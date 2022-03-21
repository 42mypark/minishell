/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:38:17 by mypark            #+#    #+#             */
/*   Updated: 2022/03/21 23:35:40 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_tree.h"

static t_tokens	*extract_tokens(t_tokens *tks, t_tokens_node *curr)
{
	t_tokens	*tmp;
	t_tokens	*new;

	tmp = cut_tokens_back(tks, curr->next); // can be optimized
	new = cut_tokens_back(tks, curr);
	tks = merge_tokens(tks, tmp);
	return (new);
}

int	parse_redir(t_parsetree_node *pt_node)
{
	t_tokens		*tks;
	t_token			*tk;
	t_tokens_node	*curr;
	t_tokens		*new;

	tks = pt_node->tokens;
	curr = tks->head;
	while (curr != tks->tail)
	{
		pass_parenthesis(curr);
		tk = curr->content;
		if (tk->type == IRD || tk->type == ORD \
			|| tk->type == ARD || tk->type == HRD)
		{
			syntax_error_check(curr);
			new = extract_tokens(tks, curr);
			pt_node->right = new_parsetree_node(new, pt_node);
			pt_node->left = new_parsetree_node(tks, pt_node);
			pt_node->parsed = 1;
			return (1);
		}
		curr = curr->next;
	}
	syntax_error_check(tks->tail);
	return (0);
}
