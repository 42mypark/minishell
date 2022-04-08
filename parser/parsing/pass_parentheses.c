/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass_parentheses.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:38:58 by mypark            #+#    #+#             */
/*   Updated: 2022/04/08 16:24:17 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_tokens_node	*pass_parentheses_forward(t_tokens_node *curr)
{
	t_token	*tk;
	int		cnt;

	tk = curr->content;
	cnt = (tk->type == TK_RPT);
	while (cnt)
	{
		curr = curr->prev;
		tk = curr->content;
		if (tk->type == TK_LPT)
			cnt--;
		if (tk->type == TK_RPT)
			cnt++;
	}
	return (curr);
}

t_tokens_node	*pass_parentheses_backward(t_tokens_node *curr)
{
	t_token	*tk;
	int		cnt;

	tk = curr->content;
	cnt = (tk->type == TK_LPT);
	while (cnt)
	{
		curr = curr->next;
		tk = curr->content;
		if (tk->type == TK_LPT)
			cnt++;
		if (tk->type == TK_RPT)
			cnt--;
	}
	return (curr);
}
