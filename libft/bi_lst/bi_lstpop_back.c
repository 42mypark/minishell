/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_lstpop_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 19:30:35 by dha               #+#    #+#             */
/*   Updated: 2022/03/15 00:43:09 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bi_lst.h"

t_bi_lst	*bi_lstpop_back(t_bi_lst *head)
{
	t_bi_lst	*last;
	t_bi_lst	*prev;

	if (head == 0)
		return (0);
	last = bi_lstlast(head);
	prev = last->prev;
	if (prev)
		prev->next = 0;
	last->prev = 0;
	return (last);
}
