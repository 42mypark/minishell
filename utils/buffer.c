/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:36:47 by mypark            #+#    #+#             */
/*   Updated: 2022/04/09 19:26:23 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "expansion_record.h"
#include "libft.h"
#include "utils.h"

void	init_buffer(t_buffer *buf)
{
	buf->start = 0;
	buf->space = 0;
	buf->len = 0;
	buf->cnt = 0;
	buf->quoted = 0;
	buf->expansion_record = NULL;
}

void	reset_buffer(t_buffer *buf)
{
	free(buf->space);
	free_expansion_record(buf->expansion_record);
	init_buffer(buf);
}

void	clear_buffer(t_buffer *buf)
{
	buf->len = 0;
	buf->space[0] = '\0';
	buf->start = 0;
	buf->quoted = 0;
	free_expansion_record(buf->expansion_record);
	buf->expansion_record = NULL;
}

void	expand_buffer(t_buffer *buf)
{
	if (buf->space == 0)
	{
		buf->space = ft_calloc(1, BUFFER_SIZE);
		buf->cnt = 1;
		if (buf->space == 0)
			print_malloc_error();
	}
	else if (buf->len == buf->cnt * BUFFER_SIZE - 1)
	{
		buf->cnt++;
		buf->space = ft_realloc(buf->space, buf->cnt * BUFFER_SIZE);
		if (buf->space == 0)
			print_malloc_error();
	}
}
