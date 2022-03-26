/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   issue_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:36:47 by mypark            #+#    #+#             */
/*   Updated: 2022/03/26 20:48:22 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer_utils.h"
#include "token.h"
#include "utils.h"

void	issue_token(t_tokens *tks, t_buffer *buf)
{
	t_token	*tk;

	tk = new_token(to_enum_token(buf->space), buf->space);
	if (buf->ep_rec)
	{
		tk->type = EXPANDED_STR;
		tk->ep_rec = dup_ep_rec(buf->ep_rec);
	}
	tks->push_tail(tks, tk);
	clear_buffer(buf);
}
