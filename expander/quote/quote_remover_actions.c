/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_remover_actions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:21:57 by mypark            #+#    #+#             */
/*   Updated: 2022/03/27 13:35:05 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "quote_remover_utils.h"

t_quote_remover_state	quote_remover_chars(t_buffer *buf, char input)
{
	if (input == '\"')
		return (Q_DOUBLE_QUOTE);
	if (input == '\'')
		return (Q_SINGLE_QUOTE);
	push_buffer(buf, input);
	return (Q_CHARS);
}

t_quote_remover_state	quote_remover_double_quote(t_buffer *buf, char input)
{
	if (input == '\"')
		return (Q_CHARS);
	push_buffer(buf, input);
	return (Q_DOUBLE_QUOTE);
}

t_quote_remover_state	quote_remover_single_quote(t_buffer *buf, char input)
{
	if (input == '\'')
		return (Q_CHARS);
	push_buffer(buf, input);
	return (Q_SINGLE_QUOTE);
}
