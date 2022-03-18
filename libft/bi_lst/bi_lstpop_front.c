/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_lstpop_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 19:30:35 by dha               #+#    #+#             */
/*   Updated: 2022/03/13 20:29:31 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bi_lst.h"

t_bi_lst	*bi_lstpop_front(t_bi_lst **head)
{
	t_bi_lst	*next;
	t_bi_lst	*prev;

	if (head == 0 || *head == 0)
		return (0);
	next = (*head)->next;
	prev = (*head);
	prev->next = 0;
	if (next != 0)
		next->prev = 0;
	(*head) = next;
	return (prev);
}
