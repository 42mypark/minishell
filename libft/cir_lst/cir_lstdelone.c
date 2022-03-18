/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cir_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 23:16:36 by dha               #+#    #+#             */
/*   Updated: 2022/03/15 00:56:37 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cir_lst.h"
#include <stdlib.h>

void	cir_lstdelone(t_cir_lst *curr, void (*del)(void *))
{
	if (curr == 0)
		return ;
	if (curr->prev)
		curr->prev->next = curr->next;
	if (curr->next)
		curr->next->prev = curr->prev;
	del(curr->content);
	free(curr);
}
