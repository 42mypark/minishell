/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_tokens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:16:25 by mypark            #+#    #+#             */
/*   Updated: 2022/03/21 14:34:43 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

t_tokens	*cut_tokens_back(t_tokens *tks, t_tokens_node *curr)
{
	t_tokens	*new;
	t_token		*tk;

	if (tks->tail == curr)
		return (NULL);
	new = new_tokens();
	while (tks->tail != curr)
	{
		tk = tks->pop_tail(tks);
		new->push_head(tks, tk);
	}
	return (new);
}

t_tokens	*cut_tokens_front(t_tokens *tks, t_tokens_node *curr)
{
	t_tokens	*new;
	t_token		*tk;

	if (tks->head == curr)
		return (NULL);
	new = new_tokens();
	while (tks->head != curr)
	{
		tk = tks->pop_head(tks);
		new->push_tail(tks, tk);
	}
	return (new);
}