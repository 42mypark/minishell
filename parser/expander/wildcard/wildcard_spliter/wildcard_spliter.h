/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_spliter.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 23:35:11 by mypark            #+#    #+#             */
/*   Updated: 2022/04/22 08:06:21 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WILDCARD_SPLITER_H
# define WILDCARD_SPLITER_H
# include "token.h"
# include "buffer.h"
# include "expansion_record.h"

typedef enum e_wildcard_spliter_state
{
	WS_CHARS,
	WS_SINGLE_QUOTE,
	WS_DOUBLE_QUOTE
}			t_wildcard_spliter_state;

typedef struct s_wildcard_spliter
{
	t_wildcard_spliter_state	state;
	t_buffer					*buf;
	t_tokens					*tokens;
	t_token						*origin;
	void						(*actions[3])(struct s_wildcard_spliter *, int);
}				t_wildcard_spliter;

void	wildcard_spliter_chars(\
	t_wildcard_spliter *spliter, \
		int index\
);
void	wildcard_spliter_single_quote(\
	t_wildcard_spliter *spliter, \
		int index\
);
void	wildcard_spliter_double_quote(\
	t_wildcard_spliter *spliter, \
		int index\
);

#endif
