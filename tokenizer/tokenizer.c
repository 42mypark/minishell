/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:52:29 by mypark            #+#    #+#             */
/*   Updated: 2022/03/27 13:48:43 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer_utils.h"
#include "token.h"
#include "utils.h"
#include "test.h"
#include "error.h"
#include "libft.h"

static t_tokenizer_state	tokenizer_blank(t_buffer *buf, char input)
{
	if (is_blank(input))
		return (T_BLANK);
	push_buffer(buf, input);
	if (is_meta(input))
		return (T_SINGLE_META);
	if (input == '\'')
		return (T_SINGLE_QUOTE);
	if (input == '\"')
		return (T_DOUBLE_QUOTE);
	return (T_CHARS);
}

void	tokenizer(t_tokens *tks, char *readline)
{
	t_buffer			buf;
	t_tokenizer_state	s;

	init_buffer(&buf);
	s = T_BLANK;
	while (*readline)
	{
		expand_buffer(&buf);
		if (s == T_BLANK)
			s = tokenizer_blank(&buf, *readline);
		if (s == T_SINGLE_QUOTE)
			s = tokenizer_single_quote(&buf, *readline);
		if (s == T_DOUBLE_QUOTE)
			s = tokenizer_double_quote(&buf, *readline);
		if (s == T_CHARS)
			s = tokenizer_chars(tks, &buf, *readline);
		if (s == T_SINGLE_META)
			s = tokenizer_single_meta(tks, &buf, *readline);
		if (s == T_DOUBLE_META)
			s = tokenizer_double_meta(tks, &buf, *readline);
		readline++;
	}
	if (buf.len)
		issue_token(tks, &buf);
	reset_buffer(&buf);
}
