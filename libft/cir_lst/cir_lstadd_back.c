/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cir_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 23:16:32 by dha               #+#    #+#             */
/*   Updated: 2022/03/15 00:56:37 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cir_lst.h"

void	cir_lstadd_back(t_cir_lst *head, t_cir_lst *new)
{
	t_cir_lst	*tail;

	if (head == 0 || new == 0)
		return ;
	tail = head->prev;
	new->next = head;
	new->prev = tail;
	head->prev = new;
	tail->next = new;
}
