/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cir_lstadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:06:13 by mypark            #+#    #+#             */
/*   Updated: 2022/03/23 16:06:14 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cir_lst.h"

void	cir_lstadd_front(t_cir_lst **head, t_cir_lst *new)
{
	t_cir_lst	*tail;

	if (head == 0 || new == 0)
		return ;
	if (*head == 0)
		*head = new;
	else
	{
		tail = (*head)->prev;
		new->next = *head;
		new->prev = tail;
		(*head)->prev = new;
		tail->next = new;
		(*head) = new;
	}
}
