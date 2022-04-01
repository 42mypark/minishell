/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edge_parentheses.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:31:39 by mypark            #+#    #+#             */
/*   Updated: 2022/04/01 22:37:10 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_utils.h"

int	is_edge_parentheses(t_parsetree_node *pt_node)
{
	t_token		*first;
	t_token		*last;
	t_tokens	*tks;

	tks = pt_node->tokens;
	first = tks->head->content;
	last = tks->tail->content;
	if (first->type == LPT && last->type == RPT)
		return (1);
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
