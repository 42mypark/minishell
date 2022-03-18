/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cir_lstsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 23:16:49 by dha               #+#    #+#             */
/*   Updated: 2022/03/15 01:03:04 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cir_lst.h"

int	cir_lstsize(t_cir_lst *head)
{
	int			size;
	t_cir_lst	*curr;

	size = 1;
	curr = head->next;
	while (curr != head)
	{
		size++;
		curr = curr->next;
	}
	return (size);
}
