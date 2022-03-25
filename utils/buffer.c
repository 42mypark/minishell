/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:36:47 by mypark            #+#    #+#             */
/*   Updated: 2022/03/25 19:47:47 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "libft.h"
#include "error.h"

void	reset_buffer(t_buffer *buf)
{
	free(buf->space);
	buf->space = 0;
	buf->len = 0;
	buf->cnt = 0;
	buf->ep_end = 0;
	buf->ep_start = 0;
}

void	init_buffer(t_buffer *buf)
{
	buf->space = 0;
	buf->len = 0;
	buf->cnt = 0;
	buf->ep_end = 0;
	buf->ep_start = 0;
}

void	clear_buffer(t_buffer *buf)
{
	buf->len = 0;
	buf->space[buf->len] = '\0';
	buf->ep_end = 0;
	buf->ep_start = 0;
}

void	push_buffer(t_buffer *buf, char input)
{
	if (input == '\0')
		return ;
	buf->space[buf->len++] = input;
	buf->space[buf->len] = '\0';
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
	else if (buf->len == buf->cnt * BUFFER_SIZE)
	{
		buf->cnt++;
		buf->space = ft_realloc(buf->space, buf->cnt * BUFFER_SIZE);
		if (buf->space == 0)
			print_malloc_error();
	}
}
