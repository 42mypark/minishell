/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   issue_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:36:47 by mypark            #+#    #+#             */
/*   Updated: 2022/03/24 03:36:40 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer_utils.h"
#include "token.h"
#include "utils.h"

void	issue_token(t_tokens *tks, t_buffer *buf)
{
	tks->push_tail(tks, new_token(to_enum_token(buf->space), buf->space));
	clear_buffer(buf);
}
