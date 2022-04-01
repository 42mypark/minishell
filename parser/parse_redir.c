/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:38:17 by mypark            #+#    #+#             */
/*   Updated: 2022/04/01 22:45:15 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_utils.h"
#include "test.h"

static t_tokens	*extract_tokens(t_tokens *tks, t_tokens **rem, \
								t_tokens_node *curr)
{
	t_tokens	*back;
	t_tokens	*front;
	t_tokens	*one;

	back = cut_tokens_back(tks, curr->next);
	one = cut_tokens_back(tks, curr);
	front = cut_tokens_front(tks, curr);
	*rem = merge_tokens(front, back);
	return (one);
}

int	parse_redir(t_parsetree_node *pt_node)
{
	t_tokens		*tks;
	t_token			*tk;
	t_tokens_node	*curr;
	t_tokens		*one;
	t_tokens		*rem;

	tks = pt_node->tokens;
	curr = tks->head;
	curr = pass_parentheses_backward(curr);
	while (curr != tks->tail)
	{
		tk = curr->content;
		if (tk->type == IRD || tk->type == ORD \
			|| tk->type == ARD || tk->type == HRD)
		{
			one = extract_tokens(tks, &rem, curr);
			pt_node->right = new_parsetree_node(one, pt_node);
			pt_node->left = new_parsetree_node(rem, pt_node);
			pt_node->type = to_enum_parsetree_node(tk->type);
			return (1);
		}
		curr = curr->next;
		curr = pass_parentheses_backward(curr);
	}
	return (0);
}
