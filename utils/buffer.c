/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:36:47 by mypark            #+#    #+#             */
/*   Updated: 2022/03/24 03:58:07 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	reset_buffer(t_buffer *buf, int *buf_cnt)
{
	free(buf->space);
	buf->space = 0;
	buf->len = 0;
	*buf_cnt = 0;
}

void	clear_buffer(t_buffer *buf)
{
	buf->len = 0;
	buf->space[buf->len] = '\0';
}

void	push_buffer(t_buffer *buf, char input)
{
	buf->space[buf->len++] = input;
	buf->space[buf->len] = '\0';
}

void	expand_buffer(t_buffer *buf, int *buf_cnt)
{
	if (buf->space == 0)
	{
		buf->space = ft_calloc(1, 1);
		if (buf->space == 0)
			print_malloc_error();
	}
	if (buf->len == (*buf_cnt) * BUFFER_SIZE)
	{
		(*buf_cnt)++;
		buf->space = ft_realloc(buf->space, (*buf_cnt) * BUFFER_SIZE);
		if (buf->space == 0)
			print_malloc_error();
	}
}
