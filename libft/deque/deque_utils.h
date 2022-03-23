/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:45:50 by mypark            #+#    #+#             */
/*   Updated: 2022/03/23 16:15:24 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUE_UTILS_H
# define DEQUE_UTILS_H
# include "deque.h"

void			*pop_head(t_deque *dq);
void			*pop_tail(t_deque *dq);
int				push_tail(t_deque *dq, void *content);
int				push_head(t_deque *dq, void *content);
t_deque_node	*new_deque_node(void *content);

#endif
