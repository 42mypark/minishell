/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 23:16:32 by dha               #+#    #+#             */
/*   Updated: 2022/03/15 00:38:41 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bi_lst.h"

void	bi_lstadd_front(t_bi_lst **lst, t_bi_lst *new)
{
	if (lst == 0 || new == 0)
		return ;
	new->next = *lst;
	(*lst)->prev = new;
	(*lst) = new;
}
