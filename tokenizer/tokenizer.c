/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:52:29 by mypark            #+#    #+#             */
/*   Updated: 2022/03/23 21:04:26 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "tokenizer_utils.h"
#include "test.h"
#include "error.h"

static t_tokenizer_state	tokenizer_blank(t_tokens *tks, \
											char *buf, int *len, char input)
{
	t_tokens_node	*curr;

	curr = tks->head;
	if (is_blank(input))
		return (BLANK);
	push_buffer(buf, input, len);
	if (is_meta(input))
		return (SINGLE_META);
	if (input == '\'')
		return (SINGLE_QUOTE);
	if (input == '\"')
		return (DOUBLE_QUOTE);
	return (CHARS);
}

void	tokenizer_init(\
	t_tokenizer_state (*behav[6])(t_tokens *, char *, int *, char), \
	int *buf_len, int *buf_cnt, char **buf)
{
	behav[0] = tokenizer_blank;
	behav[1] = tokenizer_single_quote;
	behav[2] = tokenizer_double_quote;
	behav[3] = tokenizer_chars;
	behav[4] = tokenizer_single_meta;
	behav[5] = tokenizer_double_meta;
	*buf_len = 0;
	*buf_cnt = 0;
	*buf = ft_calloc(1, 1);
	if (*buf == NULL)
		print_malloc_error();
}

int	tokenizer(t_tokens *tks, char *readline)
{
	char				*buf;
	int					buf_len;
	int					buf_cnt;
	t_tokenizer_state	s;
	t_tokenizer_state	(*behavior[6])(t_tokens *, char *, int *, char);

	tokenizer_init(behavior, &buf_len, &buf_cnt, &buf);
	s = BLANK;
	while (*readline)
	{
		if (buf_len == buf_cnt * BUFFER_SIZE)
			buf = ft_realloc(buf, (++buf_cnt) * BUFFER_SIZE);
		if (buf == NULL)
			print_malloc_error();
		s = behavior[s](tks, buf, &buf_len, *readline);
		readline++;
	}
	if (buf_len)
		issue_token(tks, buf, &buf_len);
	free(buf);
	return (1);
}
