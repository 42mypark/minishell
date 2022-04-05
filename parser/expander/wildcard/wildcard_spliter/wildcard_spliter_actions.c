/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_spliter_actions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 00:53:31 by mypark            #+#    #+#             */
/*   Updated: 2022/04/05 01:52:01 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wildcard_spliter.h"
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

void	wildcard_spliter_double_quote(\
	t_wildcard_spliter *spliter,
	int index\
)
{
	int		input;
	int		not_expanded;
	char	*str;

	str = spliter->origin->content;
	input = str[index];
	not_expanded = !is_expanded(spliter->origin->expansion_record, index);
	if (input == '\"' && not_expanded)
		spliter->state = WS_CHARS;
	else
	{
		push_buffer(spliter->buf, input);
		spliter->state = WS_DOUBLE_QUOTE;
	}
}

void	wildcard_spliter_single_quote(\
	t_wildcard_spliter *spliter,
	int index\
)
{
	int		input;
	int		not_expanded;
	char	*str;

	str = spliter->origin->content;
	input = str[index];
	not_expanded = !is_expanded(spliter->origin->expansion_record, index);
	if (input == '\'' && not_expanded)
		spliter->state = WS_CHARS;
	else
	{
		push_buffer(spliter->buf, input);
		spliter->state = WS_SINGLE_QUOTE;
	}
}

void	wildcard_spliter_chars(\
	t_wildcard_spliter *spliter,
	int index\
)
{
	int		input;
	int		not_expanded;
	char	*str;

	str = spliter->origin->content;
	input = str[index];
	not_expanded = !is_expanded(spliter->origin->expansion_record, index);
	if (input == '\'' && not_expanded)
		spliter->state = WS_SINGLE_QUOTE;
	else if (input == '\"' && not_expanded)
		spliter->state = WS_DOUBLE_QUOTE;
	else
	{
		if (input == '*' && spliter->buf->len != 0)
			issue_token(spliter->tokens, spliter->buf);
		else if (input != '*')
			push_buffer(spliter->buf, input);
		spliter->state = WS_CHARS;
	}
}
