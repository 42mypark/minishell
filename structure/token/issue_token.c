/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   issue_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:36:47 by mypark            #+#    #+#             */
/*   Updated: 2022/04/02 04:14:05 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer_utils.h"
#include "token.h"
#include "utils.h"
#include "expansion_record.h"

void	issue_token(t_tokens *tks, t_buffer *buf)
{
	t_token	*tk;

	tk = new_token(to_enum_token(buf->space), buf->space);
	if (buf->expansion_record)
	{
		tk->type = EXPANDED_STR;
		tk->expansion_record = dup_expansion_record(buf->expansion_record);
	}
	if (buf->quoted)
		tk->type = QUOTED_STR;
	tks->push_tail(tks, tk);
	clear_buffer(buf);
}
