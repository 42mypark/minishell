/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 23:16:44 by dha               #+#    #+#             */
/*   Updated: 2022/03/15 00:36:22 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bi_lst.h"
#include <stdlib.h>

t_bi_lst	*bi_lstnew(void *content)
{
	t_bi_lst	*new_node;

	new_node = (t_bi_lst *) malloc(sizeof(t_bi_lst));
	if (new_node == 0)
		return (0);
	new_node->content = content;
	new_node->next = 0;
	new_node->prev = 0;
	return (new_node);
}
