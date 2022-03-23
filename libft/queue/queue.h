/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:45:50 by mypark            #+#    #+#             */
/*   Updated: 2022/03/23 16:18:44 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H
# include "../cir_lst/cir_lst.h"

typedef t_cir_lst	t_queue_node;

typedef struct s_queue
{
	t_queue_node	*head;
	t_queue_node	*tail;
	int				(*push)(struct s_queue *, void *);
	void			*(*pop)(struct s_queue *);
}				t_queue;

t_queue			*new_queue(void);
void			free_queue(t_queue *q, void (*del)(void *));

#endif
