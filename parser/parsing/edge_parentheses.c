/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edge_parentheses.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:31:39 by mypark            #+#    #+#             */
/*   Updated: 2022/04/08 16:24:33 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	is_edge_parentheses(t_parsetree_node *pt_node)
{
	t_token			*first;
	t_tokens		*tks;
	t_tokens_node	*curr;
	t_token			*tk;
	int				cnt;

	tks = pt_node->tokens;
	first = tks->head->content;
	if (first->type == TK_LPT)
	{
		cnt = 1;
		curr = tks->head->next;
		while (cnt && curr != tks->tail)
		{
			tk = curr->content;
			if (tk->type == TK_RPT)
				cnt--;
			if (tk->type == TK_LPT)
				cnt++;
			curr = curr->next;
		}
		tk = curr->content;
		if (curr == tks->tail && tk->type == TK_RPT)
			return (1);
	}
	return (0);
}

void	remove_edge_parentheses(t_parsetree_node *pt_node)
{
	t_token		*tk;
	t_tokens	*tks;

	tks = pt_node->tokens;
	tk = tks->pop_head(tks);
	free_token(tk);
	tk = tks->pop_tail(tks);
	free_token(tk);
}
