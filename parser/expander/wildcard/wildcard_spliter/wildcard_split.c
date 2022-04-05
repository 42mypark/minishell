/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:06:06 by mypark            #+#    #+#             */
/*   Updated: 2022/04/05 01:57:43 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "libft.h"
#include "expansion_record.h"
#include "test.h"
#include "wildcard_spliter.h"
#include "strict.h"

static void	init_wildcard_spliter(\
	t_wildcard_spliter *spliter, \
	t_tokens *tks, \
	t_token *origin\
)
{
	spliter->state = WS_CHARS;
	spliter->buf = strict_malloc(sizeof(t_buffer), 1);
	init_buffer(spliter->buf);
	spliter->tokens = tks;
	spliter->origin = origin;
	spliter->actions[0] = wildcard_spliter_chars;
	spliter->actions[1] = wildcard_spliter_single_quote;
	spliter->actions[2] = wildcard_spliter_double_quote;
}

static void	reset_wildcard_spliter(t_wildcard_spliter *spliter)
{
	reset_buffer(spliter->buf);
	free(spliter->buf);
}

static void	wildcard_spliter(t_tokens *tks, t_token *origin)
{
	t_wildcard_spliter			spliter;
	char						*str;
	int							i;

	init_wildcard_spliter(&spliter, tks, origin);
	str = origin->content;
	i = 0;
	while (str[i])
	{
		spliter.actions[spliter.state](&spliter, i);
		i++;
	}
	if (spliter.buf->len)
		issue_token(spliter.tokens, spliter.buf);
	reset_wildcard_spliter(&spliter);
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
