/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:06:06 by mypark            #+#    #+#             */
/*   Updated: 2022/04/02 01:32:43 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "libft.h"
#include "expansion_record.h"
#include "test.h"
#include "wildcard_expander_utils.h"

static void	wildcard_spliter(t_tokens *tks, t_token *origin)
{
	t_buffer					buf;
	char						*str;
	int							i;
	t_wildcard_spliter_state	s;

	init_buffer(&buf);
	str = origin->content;
	s = WS_CHARS;
	i = 0;
	while (str[i])
	{
		if (s == WS_CHARS)
			s = wildcard_spliter_chars(tks, &buf, origin, i);
		else if (s == WS_DOUBLE_QUOTE)
			s = wildcard_spliter_double_quote(&buf, origin, i);
		else if (s == WS_SINGLE_QUOTE)
			s = wildcard_spliter_single_quote(&buf, origin, i);
		i++;
	}
	if (buf.len)
		issue_token(tks, &buf);
	reset_buffer(&buf);
}

char	**wildcard_split(t_token *origin)
{
	t_tokens		*tks;
	char			**formats;

	tks = new_tokens();
	wildcard_spliter(tks, origin);
	formats = tokens_to_splited(tks);
	free_tokens(tks);
	return (formats);
}
