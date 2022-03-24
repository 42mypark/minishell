/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_behavior.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 01:09:36 by mypark            #+#    #+#             */
/*   Updated: 2022/03/24 02:53:21 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "tokenizer_utils.h"
#include "token.h"

t_tokenizer_state	tokenizer_chars(t_tokens *tks, \
									t_buffer *buf, char input)
{
	if (is_blank(input))
	{
		issue_token(tks, buf);
		return (T_BLANK);
	}
	if (is_meta(input))
	{
		issue_token(tks, buf);
		push_buffer(buf, input);
		return (T_SINGLE_META);
	}
	push_buffer(buf, input);
	if (input == '\'')
		return (T_SINGLE_QUOTE);
	if (input == '\"')
		return (T_DOUBLE_QUOTE);
	return (T_CHARS);
}

t_tokenizer_state	tokenizer_single_meta(t_tokens *tks, \
									t_buffer *buf, char input)
{
	if (is_blank(input))
	{
		issue_token(tks, buf);
		return (T_BLANK);
	}
	if (!is_parenthesis(input) && input == buf->space[0])
	{
		push_buffer(buf, input);
		return (T_DOUBLE_META);
	}
	issue_token(tks, buf);
	push_buffer(buf, input);
	if (is_meta(input))
		return (T_SINGLE_META);
	if (input == '\'')
		return (T_SINGLE_QUOTE);
	if (input == '\"')
		return (T_DOUBLE_QUOTE);
	return (T_CHARS);
}

t_tokenizer_state	tokenizer_double_meta(t_tokens *tks, \
									t_buffer *buf, char input)
{
	if (is_blank(input))
	{
		issue_token(tks, buf);
		return (T_BLANK);
	}
	issue_token(tks, buf);
	push_buffer(buf, input);
	if (is_meta(input))
		return (T_SINGLE_META);
	if (input == '\'')
		return (T_SINGLE_QUOTE);
	if (input == '\"')
		return (T_DOUBLE_QUOTE);
	return (T_CHARS);
}

t_tokenizer_state	tokenizer_single_quote(t_tokens *tks, \
											t_buffer *buf, char input)
{
	t_tokens_node	*curr;

	curr = tks->head;
	push_buffer(buf, input);
	if (input == '\'')
		return (T_CHARS);
	return (T_SINGLE_QUOTE);
}

t_tokenizer_state	tokenizer_double_quote(t_tokens *tks, \
											t_buffer *buf, char input)
{
	t_tokens_node	*curr;

	curr = tks->head;
	push_buffer(buf, input);
	if (input == '\"')
		return (T_CHARS);
	return (T_DOUBLE_QUOTE);
}
