/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cir_lstclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 21:50:16 by mypark            #+#    #+#             */
/*   Updated: 2022/03/15 03:15:24 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cir_lst.h"
#include <stdlib.h>

void	cir_lstclear(t_cir_lst **lst, void (*del)(void *))
{
	t_cir_lst	*node;

	if (lst == 0 || *lst == 0 || del == 0)
		return ;
	while (*lst)
	{
		node = cir_lstpop_back(lst);
		del(node->content);
		free(node);
	}
}
