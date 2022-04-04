/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 23:35:11 by mypark            #+#    #+#             */
/*   Updated: 2022/04/02 04:07:51 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# define BUFFER_SIZE 5
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
int		is_meta(char c);
int		is_blank(char c);
int		is_parenthesis(char c);
int		is_bool(char c);
int		is_redir(char c);
char	*dupenv(char *target, char **envp);
int		is_same(char *s1, char *s2);
int		set_state(int *old_state, int new_state);

#endif
