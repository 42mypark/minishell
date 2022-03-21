/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:52:29 by mypark            #+#    #+#             */
/*   Updated: 2022/03/22 01:53:46 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "tokenizer_utils.h"

static enum e_tokenizer_state	tokenizer_single_quote(t_tokens *tks, \
												char *buf, int *len, char input)
{
	tks;
	buf[(*len)++] = input;
	buf[(*len)] = '\0';
	if (input == '\'')
		return (CHARS);
	return (SINGLE_QUOTE);
}

static enum e_tokenizer_state	tokenizer_double_quote(t_tokens *tks, \
												char *buf, int *len, char input)
{
	tks;
	buf[(*len)++] = input;
	buf[(*len)] = '\0';
	if (input == '\"')
		return (CHARS);
	return (DOUBLE_QUOTE);
}

static enum e_tokenizer_state	tokenizer_blank(t_tokens *tks, \
												char *buf, int *len, char input)
{
	tks;
	if (input == ' ' || input == '\t')
		return (BLANK);
	buf[(*len)++] = input;
	buf[(*len)] = '\0';
	if (is_meta(input))
		return (SINGLE_META);
	if (input == '\'')
		return (SINGLE_QUOTE);
	if (input == '\"')
		return (DOUBLE_QUOTE);
	return (CHARS);
}

int	tokenizer(t_tokens *tks, char *readline)
{
	char					*buf;
	enum e_tokenizer_state	s;
	enum e_tokenizer_state	(*tokenizer_behavior[6])(t_tokens *tks, char *, int *, char);
	int						buf_len;
	int						buf_cnt;

	tokenizer_behavior[0] = tokenizer_blank;
	tokenizer_behavior[1] = tokenizer_single_quote;
	tokenizer_behavior[2] = tokenizer_double_quote;
	tokenizer_behavior[3] = tokenizer_chars;
	tokenizer_behavior[4] = tokenizer_single_meta;
	tokenizer_behavior[5] = tokenizer_double_meta;
	buf_len = 0;
	buf_cnt = 0;
	s = BLANK;
	while (readline)
	{
		if (buf_len == 1024 * buf_cnt)
			buf = ft_realloc(buf, (++buf_cnt) * 1024);
		if (buf == NULL)
			return (0); // ERROR
		s = tokenizer_behavior[s](tks, buf, &buf_len, *readline);
		readline++;
	}
	return (1);
}
