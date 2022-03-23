/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_deque.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:11:29 by mypark            #+#    #+#             */
/*   Updated: 2022/03/23 16:31:06 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"
#include "deque_utils.h"

int	push_tail(t_deque *dq, void *content)
{
	t_deque_node	*new;

	new = new_deque_node(content);
	if (new == 0)
		return (0);
	cir_lstadd_back(&dq->head, new);
	dq->tail = dq->head->prev;
	return (1);
}

int	push_head(t_deque *dq, void *content)
{
	t_deque_node	*new;

	new = new_deque_node(content);
	if (new == 0)
		return (0);
	cir_lstadd_front(&dq->head, new);
	dq->tail = dq->head->prev;
	return (1);
}
