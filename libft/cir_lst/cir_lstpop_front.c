/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cir_lstpop_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:08:40 by mypark            #+#    #+#             */
/*   Updated: 2022/03/23 16:08:41 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cir_lst.h"

t_cir_lst	*cir_lstpop_front(t_cir_lst **head)
{
	t_cir_lst	*next;
	t_cir_lst	*prev;
	t_cir_lst	*curr;
	int			is_one;

	if (head == 0 || *head == 0)
		return (0);
	curr = (*head);
	is_one = (curr->next == curr);
	if (is_one)
		*head = 0;
	else
	{
		next = curr->next;
		prev = curr->prev;
		prev->next = next;
		next->prev = prev;
		curr->next = curr;
		curr->prev = curr;
		(*head) = next;
	}
	return (curr);
}
