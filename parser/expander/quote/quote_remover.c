/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_remover.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:21:57 by mypark            #+#    #+#             */
/*   Updated: 2022/04/09 02:20:23 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "strict.h"
#include "quote_remover.h"
#include "expansion_record.h"

static int	jump_expanded(t_buffer *buf, int i, t_token *tk)
{
	char				*str;
	t_expansion_range	*expansion_range;
	t_expansion_record	*curr;

	if (tk->expansion_record == NULL)
		return (i);
	curr = tk->expansion_record;
	while (curr)
	{
		expansion_range = curr->content;
		if (expansion_range->start == i)
		{
			str = tk->content;
			while (i < expansion_range->end)
				push_buffer(buf, str[i++]);
			return (jump_expanded(buf, i, tk));
		}
		curr = curr->next;
	}
	return (i);
}

static void	init_quote_remover(t_quote_remover *qrm)
{
	qrm->state = Q_CHARS;
	qrm->actions[0] = quote_remover_chars;
	qrm->actions[1] = quote_remover_double_quote;
	qrm->actions[2] = quote_remover_single_quote;
	qrm->buf = strict_malloc(sizeof(t_buffer), 1);
	init_buffer(qrm->buf);
	expand_buffer(qrm->buf);
}

static void	reset_quote_remover(t_quote_remover *qrm)
{
	reset_buffer(qrm->buf);
	free(qrm->buf);
}

void	quote_remover(t_tokens *tks, t_token *tk)
{
	t_quote_remover			qrm;
	char					*str;
	int						i;

	init_quote_remover(&qrm);
	str = tk->content;
	i = 0;
	i = jump_expanded(qrm.buf, i, tk);
	while (str[i])
	{
		qrm.actions[qrm.state](&qrm, str[i]);
		if (qrm.state != Q_CHARS)
			qrm.buf->quoted = 1;
		i = jump_expanded(qrm.buf, ++i, tk);
	}
	//if (qrm.buf->len)
	issue_token(tks, qrm.buf);
	reset_quote_remover(&qrm);
}
