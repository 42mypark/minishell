/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cir_lstfind_forward.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:07:02 by mypark            #+#    #+#             */
/*   Updated: 2022/03/23 16:07:23 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cir_lst.h"

t_cir_lst	*cir_lstfind_forward(t_cir_lst *curr, void *target, \
								int (*cmp)(void *, void *))
{
	t_cir_lst	*memo;

	if (curr == 0 || target == 0)
		return (0);
	if (cmp(target, curr->content) == 0)
		return (curr);
	memo = curr;
	curr = curr->prev;
	while (curr != memo)
	{
		if (cmp(target, curr->content) == 0)
			return (curr);
		curr = curr->prev;
	}
	return (0);
}
