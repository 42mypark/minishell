/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 23:35:11 by mypark            #+#    #+#             */
/*   Updated: 2022/03/24 04:02:32 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# define BUFFER_SIZE 128

typedef struct s_buf
{
	char	*space;
	int		len;
	int		cnt;
}				t_buffer;

void	clear_buffer(t_buffer *buf);
void	push_buffer(t_buffer *buf, char input);
void	expand_buffer(t_buffer *buf);
void	reset_buffer(t_buffer *buf);
int		is_meta(char c);
int		is_blank(char c);
int		is_parenthesis(char c);
int		is_bool(char c);
int		is_redir(char c);

#endif