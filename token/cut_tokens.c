/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_tokens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:16:25 by mypark            #+#    #+#             */
/*   Updated: 2022/03/18 17:26:22 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

t_tokens	*cut_tokens_backward()
{
	
}

t_tokens	*cut_tokens_forward(t_tokens *tks, t_tokens_node *curr)
{
	t_tokens	*new;
	t_token		*tk;

	new = new_tokens();
	if (new == NULL)
		return (NULL);
	while (tks->head != curr)
	{
		tk = tks->pop_head(tks);
		new->push_tail(tks, tk);
	}
	return (new);
}