/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_deque.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:10:11 by mypark            #+#    #+#             */
/*   Updated: 2022/03/23 16:30:38 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"
#include <stdlib.h>

void	*pop_head(struct s_deque *dq)
{
	t_deque_node	*node;
	void			*content;

	node = cir_lstpop_front(&dq->head);
	if (dq->head)
		dq->tail = dq->head->prev;
	else
		dq->tail = 0;
	content = node->content;
	free(node);
	return (content);
}

void	*pop_tail(struct s_deque *dq)
{
	t_deque_node	*node;
	void			*content;

	node = cir_lstpop_back(&dq->head);
	if (dq->head)
		dq->tail = dq->head->prev;
	else
		dq->tail = 0;
	content = node->content;
	free(node);
	return (content);
}
