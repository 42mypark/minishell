/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:36:47 by mypark            #+#    #+#             */
/*   Updated: 2022/03/22 18:22:37 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer_utils.h"

static void	init_buffer(char *buf, int *len)
{
	*len = 0;
	buf[(*len)] = '\0';
}

void	push_buffer(char *buf, char input, int *len)
{
	buf[(*len)++] = input;
	buf[(*len)] = '\0';
}

void	issue_token(t_tokens *tks, char *buf, int *len)
{
	tks->push_tail(tks, new_token(to_enum_token(buf), buf));
	init_buffer(buf, len);
}
