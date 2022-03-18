/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_deque.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 02:48:54 by mypark            #+#    #+#             */
/*   Updated: 2022/03/18 17:29:48 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"
#include <stdlib.h>

static void	*pop_head(struct s_deque *dq)
{
	t_deque_node	*node;
	void			*content;

	node = cir_lstpop_front(&dq->head);
	dq->tail = dq->head->prev;
	content = node->content;
	free(node);
	return (content);
}

static void	*pop_tail(struct s_deque *dq)
{
	t_deque_node	*node;
	void			*content;

	node = cir_lstpop_back(&dq->head);
	dq->tail = dq->head->prev;
	content = node->content;
	free(node);
	return (content);
}

static t_deque_node	*new_deque_node(void *content)
{
	return (cir_lstnew(content));
}

static int	push_tail(t_deque *dq, void *content)
{
	t_deque_node	*new;
	
	new = new_deque_node(content);
	if (new == NULL)
		return (0);
	cir_lstadd_back(dq->head, new);
	dq->tail = dq->head->prev;
	return (1);
}

static int	push_head(t_deque *dq, void *content)
{
	t_deque_node	*new;
	
	new = new_deque_node(content);
	if (new == NULL)
		return (0);
	cir_lstadd_front(&dq->head, new);
	dq->tail = dq->head->prev;
	return (1);
}

t_deque	*new_deque()
{
	t_deque	*dq;

	dq = malloc(sizeof(t_deque));
	if (dq == NULL)
		return (NULL);
	dq->pop_head = pop_head;
	dq->pop_tail = pop_tail;
	dq->push_head = push_head;
	dq->push_tail = push_tail;
	return (dq);
}
