/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass_prth.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:38:58 by mypark            #+#    #+#             */
/*   Updated: 2022/03/21 14:05:21 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_tree.h"

t_tokens_node	*pass_parenthesis(t_tokens_node *curr)
{
	t_token	*tk;
	int		cnt;

	tk = curr->content;
	cnt = tk->type == RPT;
	if (cnt)
		syntax_error_check(curr->prev, curr);
	while (cnt)
	{
		curr = curr->prev;
		tk = curr->content;
		if (tk->type == LPT)
			cnt--;
		if (tk->type == RPT)
			cnt++;
	}
	return (curr);
}
