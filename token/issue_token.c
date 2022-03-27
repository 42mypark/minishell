/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   issue_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:36:47 by mypark            #+#    #+#             */
/*   Updated: 2022/03/27 13:15:36 by mypark           ###   ########.fr       */
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
	tks->push_tail(tks, tk);
	clear_buffer(buf);
}
