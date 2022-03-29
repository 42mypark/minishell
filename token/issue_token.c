/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   issue_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:36:47 by mypark            #+#    #+#             */
/*   Updated: 2022/03/29 18:07:39 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer_utils.h"
#include "token.h"
#include "utils.h"
#include "ep_rec.h"
#include "test.h"

void	issue_token(t_tokens *tks, t_buffer *buf)
{
	t_token	*tk;

	tk = new_token(to_enum_token(buf->space), buf->space);
	if (buf->ep_rec)
	{
		tk->type = EXPANDED_STR;
		tk->ep_rec = dup_ep_rec(buf->ep_rec);
	}
	if (buf->quoted)
		tk->type = QUOTED_STR;
	tks->push_tail(tks, tk);
	clear_buffer(buf);
}
