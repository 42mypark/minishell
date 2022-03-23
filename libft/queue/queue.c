/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 02:48:54 by mypark            #+#    #+#             */
/*   Updated: 2022/03/23 16:18:12 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"
#include <stdlib.h>

static void	*pop(struct s_queue *q)
{
	t_queue_node	*node;
	void			*content;

	node = cir_lstpop_front(&q->head);
	q->tail = q->head->prev;
	content = node->content;
	free(node);
	return (content);
}

static t_queue_node	*new_queue_node(void *content)
{
	return (cir_lstnew(content));
}

static int	push(t_queue *q, void *content)
{
	t_queue_node	*new;

	new = new_queue_node(content);
	if (new == 0)
		return (0);
	cir_lstadd_back(&q->head, new);
	q->tail = q->head->prev;
	return (1);
}

t_queue	*new_queue(void)
{
	t_queue	*q;

	q = malloc(sizeof(t_queue));
	q->head = NULL;
	q->tail = NULL;
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
