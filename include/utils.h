/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 23:35:11 by mypark            #+#    #+#             */
/*   Updated: 2022/03/24 01:47:59 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# define BUFFER_SIZE 1024

void	init_buffer(char *buf, int *len);
void	push_buffer(char *buf, char input, int *len);
int		is_meta(char c);
int		is_blank(char c);
int		is_parenthesis(char c);
int		is_bool(char c);
int		is_redir(char c);

#endif
