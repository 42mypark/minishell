/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   behavior.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 01:09:36 by mypark            #+#    #+#             */
/*   Updated: 2022/03/22 17:03:25 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer_utils.h"

t_tokenizer_state	tokenizer_chars(t_tokens *tks, \
									char *buf, int *len, char input)
{
	if (is_blank(input))
	{
		issue_token(tks, buf, len);
		return (BLANK);
	}
	if (is_meta(input))
	{
		issue_token(tks, buf, len);
		push_buffer(buf, input, len);
		return (SINGLE_META);
	}
	push_buffer(buf, input, len);
	if (input == '\'')
		return (SINGLE_QUOTE);
	if (input == '\"')
		return (DOUBLE_QUOTE);
	return (CHARS);
}

t_tokenizer_state	tokenizer_single_meta(t_tokens *tks, \
									char *buf, int *len, char input)
{
	if (is_blank(input))
	{
		issue_token(tks, buf, len);
		return (BLANK);
	}
	if (!is_parenthesis(input) && input == buf[0])
	{
		push_buffer(buf, input, len);
		return (DOUBLE_META);
	}
	issue_token(tks, buf, len);
	push_buffer(buf, input, len);
	if (is_meta(input))
		return (SINGLE_META);
	if (input == '\'')
		return (SINGLE_QUOTE);
	if (input == '\"')
		return (DOUBLE_QUOTE);
	return (CHARS);
}

t_tokenizer_state	tokenizer_double_meta(t_tokens *tks, \
									char *buf, int *len, char input)
{
	if (is_blank(input))
	{
		issue_token(tks, buf, len);
		return (BLANK);
	}
	issue_token(tks, buf, len);
	push_buffer(buf, input, len);
	if (is_meta(input))
		return (SINGLE_META);
	if (input == '\'')
		return (SINGLE_QUOTE);
	if (input == '\"')
		return (DOUBLE_QUOTE);
	return (CHARS);
}

t_tokenizer_state	tokenizer_single_quote(t_tokens *tks, \
											char *buf, int *len, char input)
{
	t_tokens_node	*curr;

	curr = tks->head;
	push_buffer(buf, input, len);
	if (input == '\'')
		return (CHARS);
	return (SINGLE_QUOTE);
}

t_tokenizer_state	tokenizer_double_quote(t_tokens *tks, \
											char *buf, int *len, char input)
{
	t_tokens_node	*curr;

	curr = tks->head;
	push_buffer(buf, input, len);
	if (input == '\"')
		return (CHARS);
	return (DOUBLE_QUOTE);
}
