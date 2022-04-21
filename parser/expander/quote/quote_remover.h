/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_remover.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 23:35:11 by mypark            #+#    #+#             */
/*   Updated: 2022/04/22 08:20:10 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUOTE_REMOVER_H
# define QUOTE_REMOVER_H
# include "buffer.h"
# include "token.h"

typedef enum e_quote_remover_state
{
	Q_CHARS,
	Q_DOUBLE_QUOTE,
	Q_SINGLE_QUOTE
}			t_quote_remover_state;

typedef struct s_quote_remover
{
	t_quote_remover_state	state;
	t_buffer				*buf;
	void					(*actions[3])(struct s_quote_remover *, char);
}				t_quote_remover;

void	quote_remover_chars(t_quote_remover *qrm, char input);
void	quote_remover_double_quote(t_quote_remover *qrm, char input);
void	quote_remover_single_quote(t_quote_remover *qrm, char input);

#endif
