/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:52:29 by mypark            #+#    #+#             */
/*   Updated: 2022/03/25 20:55:29 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer_utils.h"
#include "token.h"
#include "utils.h"
#include "test.h"
#include "error.h"
#include "libft.h"

static t_tokenizer_state	tokenizer_blank(t_tokens *tks, \
											t_buffer *buf, char input)
{
	t_tokens_node	*curr;

	curr = tks->head;
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

void	tokenizer_init(\
	t_tokenizer_state (*behav[6])(t_tokens *, t_buffer *, char), \
	t_buffer *buf)
{
	behav[0] = tokenizer_blank;
	behav[1] = tokenizer_single_quote;
	behav[2] = tokenizer_double_quote;
	behav[3] = tokenizer_chars;
	behav[4] = tokenizer_single_meta;
	behav[5] = tokenizer_double_meta;
	init_buffer(buf);
}

void	tokenizer(t_tokens *tks, char *readline)
{
	t_buffer			buf;
	t_tokenizer_state	s;
	t_tokenizer_state	(*actions[6])(t_tokens *, t_buffer *, char);

	tokenizer_init(actions, &buf);
	s = T_BLANK;
	while (*readline)
	{
		expand_buffer(&buf);
		s = actions[s](tks, &buf, *readline);
		readline++;
	}
	if (buf.len)
		issue_token(tks, &buf);
	reset_buffer(&buf);
}
