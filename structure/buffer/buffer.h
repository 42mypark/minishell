/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 23:35:11 by mypark            #+#    #+#             */
/*   Updated: 2022/04/22 07:38:27 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_H
# define BUFFER_H
# define BUFFER_SIZE 128
# include "libft.h"

typedef struct s_buf
{
	char	*space;
	int		len;
	int		cnt;
	int		start;
	int		quoted;
	t_list	*expansion_record;
}				t_buffer;

void	clear_buffer(t_buffer *buf);
void	push_buffer(t_buffer *buf, char input);
void	expand_buffer(t_buffer *buf);
void	reset_buffer(t_buffer *buf);
void	init_buffer(t_buffer *buf);
void	push_buffer_str(t_buffer *buf, char *str);

#endif
