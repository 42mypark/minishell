/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 01:38:04 by mypark            #+#    #+#             */
/*   Updated: 2022/03/13 15:15:07 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bi_lst.h"

void	bi_lstadd_back(t_bi_lst **lst, t_bi_lst *new)
{
	t_bi_lst	*last;

	if (lst == 0 || new == 0)
		return ;
	if (*lst)
	{
		last = bi_lstlast(*lst);
		last->next = new;
		new->prev = last;
	}
	else
		*lst = new;
}
