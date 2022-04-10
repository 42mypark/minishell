/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_remover_actions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:21:57 by mypark            #+#    #+#             */
/*   Updated: 2022/04/11 00:28:55 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "quote_remover.h"

void	quote_remover_chars(t_quote_remover *qrm, char input)
{
	if (input == '\"')
	{
		qrm->state = Q_DOUBLE_QUOTE;
		return ;
	}
	if (input == '\'')
	{
		qrm->state = Q_SINGLE_QUOTE;
		return ;
	}
	push_buffer(qrm->buf, input);
	return ;
}

void	quote_remover_double_quote(t_quote_remover *qrm, char input)
{
	if (input == '\"')
	{
		qrm->state = Q_CHARS;
		return ;
	}
	push_buffer(qrm->buf, input);
	return ;
}

void	quote_remover_single_quote(t_quote_remover *qrm, char input)
{
	if (input == '\'')
	{
		qrm->state = Q_CHARS;
		return ;
	}
	push_buffer(qrm->buf, input);
	return ;
}
