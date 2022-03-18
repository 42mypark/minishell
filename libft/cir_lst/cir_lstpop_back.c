/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cir_lstpop_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 19:30:35 by dha               #+#    #+#             */
/*   Updated: 2022/03/15 00:56:37 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cir_lst.h"

t_cir_lst	*cir_lstpop_back(t_cir_lst **head)
{
	t_cir_lst	*next;
	t_cir_lst	*prev;
	t_cir_lst	*curr;
	int			is_one;

	if (head == 0 || *head == 0)
		return (0);
	curr = (*head);
	is_one = (curr->prev == curr);
	if (is_one)
		*head = 0;
	else
	{
		curr = curr->prev;
		next = curr->next;
		prev = curr->prev;
		prev->next = next;
		next->prev = prev;
		curr->next = curr;
		curr->prev = curr;
	}
	return (curr);
}
