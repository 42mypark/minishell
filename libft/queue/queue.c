/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 02:48:54 by mypark            #+#    #+#             */
/*   Updated: 2022/03/17 21:07:34 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"
#include <stdlib.h>

static t_queue_node	*pop(struct s_queue *q)
{
	t_queue_node	*node;

	node = cir_lstpop_front(&q->head);
	q->tail = q->head->prev;
	return (node);
}

static void	push(t_queue *q, t_queue_node *new)
{
	cir_lstadd_back(q->head, new);
	q->tail = q->head->prev;
}

t_queue_node	*new_queue_node(void *content)
{
	return (cir_lstnew(content));
}

t_queue	*new_queue()
{
	t_queue	*q;

	q = malloc(sizeof(t_queue));
	if (q == NULL)
		return (NULL);
	q->pop = pop;
	q->push = push;
	return (q);
}

void	free_queue(t_queue *q, void (*del)(void *))
{
	cir_lstclear(&q->head, del);
	free(q);
}
