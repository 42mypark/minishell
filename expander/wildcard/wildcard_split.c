/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:06:06 by mypark            #+#    #+#             */
/*   Updated: 2022/03/30 02:21:47 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "libft.h"
#include "ep_rec.h"
#include "test.h"
#include "wildcard_expander_utils.h"

static int	count_token(t_tokens *tks)
{
	int				cnt;
	t_tokens_node	*curr;

	if (tks == NULL || tks->head == NULL)
		return (0);
	cnt = 1;
	curr = tks->head;
	while(curr != tks->tail)
	{
		cnt++;
		curr = curr->next;
	}
	return (cnt);
}

static char	**tokens_to_splited(t_tokens *tks)
{
	char			**splited;
	int				wc;
	t_tokens_node	*curr;
	t_token			*tk;

	wc = count_token(tks);
	splited = malloc(sizeof(char *) * (wc + 1));
	if (splited == NULL)
		print_malloc_error();
	splited[wc] = NULL;
	curr = tks->head;
	wc = 0;
	while(curr != tks->tail)
	{
		tk = curr->content;
		splited[wc++] = ft_strdup(tk->content);
		curr = curr->next;
	}
	if (tks->tail != NULL)
	{
		tk = tks->tail->content;
		splited[wc++] = ft_strdup(tk->content);
	}
	return (splited);
}

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
		expand_buffer(&buf);
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
