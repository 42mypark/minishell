/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 23:16:49 by dha               #+#    #+#             */
/*   Updated: 2022/03/15 00:35:42 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bi_lst.h"

int	bi_lstsize(t_bi_lst *lst)
{
	int			size;
	t_bi_lst	*curr;

	size = 0;
	curr = lst;
	while (curr)
	{
		curr = curr->next;
		size++;
	}
	return (size);
}
