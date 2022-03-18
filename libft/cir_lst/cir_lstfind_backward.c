/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cir_lstfind_backwrad.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 00:11:13 by mypark            #+#    #+#             */
/*   Updated: 2022/03/15 00:56:37 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cir_lst.h"

t_cir_lst	*cir_lstfind_backward(t_cir_lst *curr, void *target, int (*cmp)(void *, void *))
{
	t_cir_lst	*memo;

	if (curr == 0 || target == 0)
		return (0);
	if (cmp(target, curr->content) == 0)
		return (curr);
	memo = curr;
	curr = curr->next;
	while (curr != memo)
	{
		if (cmp(target, curr->content) == 0)
			return (curr);
		curr = curr->next;
	}
	return (0);
}

