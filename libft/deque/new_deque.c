/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_deque.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 02:48:54 by mypark            #+#    #+#             */
/*   Updated: 2022/03/23 16:16:20 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"
#include "deque_utils.h"
#include <stdlib.h>

t_deque_node	*new_deque_node(void *content)
{
	return (cir_lstnew(content));
}

t_deque	*new_deque(void)
{
	t_deque	*dq;

	dq = malloc(sizeof(t_deque));
	if (dq == NULL)
		return (NULL);
	dq->head = NULL;
	dq->tail = NULL;
	dq->pop_head = pop_head;
	dq->pop_tail = pop_tail;
	dq->push_head = push_head;
	dq->push_tail = push_tail;
	return (dq);
}
