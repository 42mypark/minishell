/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 23:16:36 by dha               #+#    #+#             */
/*   Updated: 2022/03/14 00:57:59 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bi_lst.h"
#include <stdlib.h>

void	bi_lstdelone(t_bi_lst *lst, void (*del)(void *))
{
	if (lst == 0)
		return ;
	if (lst->prev)
		lst->prev->next = lst->next;
	if (lst->next)
		lst->next->prev = lst->prev;
	del(lst->content);
	free(lst);
}
