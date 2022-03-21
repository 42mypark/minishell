/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:16:38 by mypark            #+#    #+#             */
/*   Updated: 2022/03/21 13:29:13 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

t_tokens	*merge_tokens(t_tokens *tks1, t_tokens *tks2)
{
	t_token	*tk;
	
	while (tks2->head)
	{
		tk = tks2->pop_head(tks2);
		tks1->push_tail(tks1, tk);
	}
	free_tokens(tks2);
	return (tks1);
}