/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_buffer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:36:47 by mypark            #+#    #+#             */
/*   Updated: 2022/04/09 17:55:47 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	push_buffer(t_buffer *buf, char input)
{
	if (input == '\0')
		return ;
	expand_buffer(buf);
	buf->space[buf->len++] = input;
	buf->space[buf->len] = '\0';
}

void	push_buffer_str(t_buffer *buf, char *str)
{
	while (*str)
	{
		push_buffer(buf, *str);
		str++;
	}
}
