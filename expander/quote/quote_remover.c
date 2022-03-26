/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_remover.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:21:57 by mypark            #+#    #+#             */
/*   Updated: 2022/03/26 22:05:00 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "parse_tree.h"
#include "quote_remover_utils.h"
#include "ep_rec.h"

static int	jump_expanded(t_buffer *buf, int i, t_token *tk)
{
	int				start;
	int				end;
	char			*str;
	t_ep_range		*ep_range;
	static t_ep_rec	*curr = NULL;

	if (tk->ep_rec == NULL || tk->ep_rec->content == NULL)
		return (i);
	if (curr != NULL)
		ep_range = curr->content;
	else
	{
		ep_range = tk->ep_rec->content;
		curr = tk->ep_rec;
	}
	if (i != ep_range->start)
		return (i);
	str = tk->content;
	i += (str[i] == '\"');
	while (i < ep_range->end)
		push_buffer(buf, str[i++]);
	curr = curr->next;
	return (end);
}

static void	quote_remover(t_tokens *tks, t_token *tk)
{
	t_quote_remover_state	s;
	t_buffer				buf;
	int						i;
	char					*str;

	init_buffer(&buf);
	expand_buffer(&buf);
	str = tk->content;
	s = Q_CHARS;
	i = 0;
	i = jump_expanded(&buf, i, tk);
	while (str[i])
	{
		if (s == Q_CHARS)
			s = quote_remover_chars(&buf, str[i]);
		if (s == Q_DOUBLE_QUOTE)
			s = quote_remover_double_quote(&buf, str[i]);
		if (s == Q_SINGLE_QUOTE)
			s = quote_remover_single_quote(&buf, str[i]);
		i = jump_expanded(&buf, ++i, tk);
		expand_buffer(&buf);
	}
	if (buf.len)
		issue_token(tks, &buf);
	reset_buffer(&buf);
}

t_tokens	*expand_token_quote(t_token *tk, char **envp)
{
	t_tokens	*tks;

	envp = NULL;
	tks = new_tokens();
	quote_remover(tks, tk);
	free_token(tk);
	return (tks);
}

void	remove_quote(t_parsetree_node *node, char **envp)
{
	expand_tour_tree(node, expand_token_quote, envp);
}
