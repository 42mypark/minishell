/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_actions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 01:09:36 by mypark            #+#    #+#             */
/*   Updated: 2022/04/05 00:51:12 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "token.h"
#include "tokenizer.h"

void	tokenizer_chars(t_tokenizer *tokenizer, char input)
{
	if (is_blank(input))
	{
		issue_token(tokenizer->tokens, tokenizer->buf);
		tokenizer->state = T_BLANK;
	}
	else if (is_meta(input))
	{
		issue_token(tokenizer->tokens, tokenizer->buf);
		push_buffer(tokenizer->buf, input);
		tokenizer->state = T_SINGLE_META;
	}
	else
	{
		push_buffer(tokenizer->buf, input);
		if (input == '\'')
			tokenizer->state = T_SINGLE_QUOTE;
		else if (input == '\"')
			tokenizer->state = T_DOUBLE_QUOTE;
		else
			tokenizer->state = T_CHARS;
	}
}

void	tokenizer_single_quote(t_tokenizer *tokenizer, char input)
{
	push_buffer(tokenizer->buf, input);
	if (input == '\'')
		tokenizer->state = T_CHARS;
	else
		tokenizer->state = T_SINGLE_QUOTE;
}

void	tokenizer_double_quote(t_tokenizer *tokenizer, char input)
{
	push_buffer(tokenizer->buf, input);
	if (input == '\"')
		tokenizer->state = T_CHARS;
	else
		tokenizer->state = T_DOUBLE_QUOTE;
}

void	tokenizer_single_meta(t_tokenizer *tokenizer, char input)
{
	if (is_blank(input))
	{
		issue_token(tokenizer->tokens, tokenizer->buf);
		tokenizer->state = T_BLANK;
	}
	else if (!is_parenthesis(input) && input == tokenizer->buf->space[0])
	{
		push_buffer(tokenizer->buf, input);
		tokenizer->state = T_DOUBLE_META;
	}
	else
	{
		issue_token(tokenizer->tokens, tokenizer->buf);
		push_buffer(tokenizer->buf, input);
		if (is_meta(input))
			tokenizer->state = T_SINGLE_META;
		else if (input == '\'')
			tokenizer->state = T_SINGLE_QUOTE;
		else if (input == '\"')
			tokenizer->state = T_DOUBLE_QUOTE;
		else
			tokenizer->state = T_CHARS;
	}
}

void	tokenizer_double_meta(t_tokenizer *tokenizer, char input)
{
	if (is_blank(input))
	{
		issue_token(tokenizer->tokens, tokenizer->buf);
		tokenizer->state = T_BLANK;
	}
	else
	{
		issue_token(tokenizer->tokens, tokenizer->buf);
		push_buffer(tokenizer->buf, input);
		if (is_meta(input))
			tokenizer->state = T_SINGLE_META;
		else if (input == '\'')
			tokenizer->state = T_SINGLE_QUOTE;
		else if (input == '\"')
			tokenizer->state = T_DOUBLE_QUOTE;
		else
			tokenizer->state = T_CHARS;
	}
}
