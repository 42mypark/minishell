/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_lstfind_backward.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 00:11:13 by mypark            #+#    #+#             */
/*   Updated: 2022/03/23 16:05:31 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bi_lst.h"

t_bi_lst	*bi_lstfind_backward(t_bi_lst *curr, void *target, \
								int (*cmp)(void *, void *))
{
	if (curr == 0 || target == 0)
		return (0);
	while (curr)
	{
		if (cmp(target, curr->content) == 0)
			break ;
		curr = curr->next;
	}
	return (curr);
}
