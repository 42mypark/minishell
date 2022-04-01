/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_spliter_actions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 00:53:31 by mypark            #+#    #+#             */
/*   Updated: 2022/04/02 01:32:43 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wildcard_expander_utils.h"
#include "expansion_record.h"

static int	is_expanded(t_expansion_record *expansion_record, int i)
{
	t_expansion_range	*range;
	t_expansion_record	*curr;

	curr = expansion_record;
	while (curr)
	{
		range = curr->content;
		if (i >= range->start && i < range->end)
			return (1);
		curr = curr->next;
	}
	return (0);
}

t_wildcard_spliter_state	wildcard_spliter_double_quote(\
	t_buffer *buf, \
	t_token *origin, \
	int i)
{
	int		input;
	int		not_expanded;
	char	*str;

	str = origin->content;
	input = str[i];
	not_expanded = !is_expanded(origin->expansion_record, i);
	if (input == '\"' && not_expanded)
		return (WS_CHARS);
	push_buffer(buf, input);
	return (WS_DOUBLE_QUOTE);
}

t_wildcard_spliter_state	wildcard_spliter_single_quote(\
	t_buffer *buf, \
	t_token *origin, \
	int i)
{
	int		input;
	int		not_expanded;
	char	*str;

	str = origin->content;
	input = str[i];
	not_expanded = !is_expanded(origin->expansion_record, i);
	if (input == '\'' && not_expanded)
		return (WS_CHARS);
	push_buffer(buf, input);
	return (WS_SINGLE_QUOTE);
}

t_wildcard_spliter_state	wildcard_spliter_chars(\
	t_tokens *tks, \
	t_buffer *buf, \
	t_token *origin, \
	int i)
{
	int		input;
	int		not_expanded;
	char	*str;

	str = origin->content;
	input = str[i];
	not_expanded = !is_expanded(origin->expansion_record, i);
	if (input == '\'' && not_expanded)
		return (WS_SINGLE_QUOTE);
	if (input == '\"' && not_expanded)
		return (WS_DOUBLE_QUOTE);
	if (input == '*' && buf->len != 0)
		issue_token(tks, buf);
	else if (input != '*')
		push_buffer(buf, input);
	return (WS_CHARS);
}
