/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:45:50 by mypark            #+#    #+#             */
/*   Updated: 2022/03/15 17:01:19 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H
# include "../cir_lst/cir_lst.h"

typedef t_cir_lst t_queue_node;

typedef struct s_queue
{
	t_queue_node	*head;
	t_queue_node	*tail;
	void			(*push)(struct s_queue *, t_queue_node *);
	t_queue_node	*(*pop)(struct s_queue *);
}				t_queue;

t_queue			*new_queue();
void			free_queue(t_queue *q, void (*del)(void *));
t_queue_node	*new_queue_node(void *content);

#endif

