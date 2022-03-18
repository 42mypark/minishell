/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cir_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 23:16:44 by dha               #+#    #+#             */
/*   Updated: 2022/03/15 00:56:37 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cir_lst.h"
#include "../libft.h"
#include <stdlib.h>

t_cir_lst	*cir_lstnew(void *content)
{
	t_cir_lst	*new_node;

	new_node = (t_cir_lst *) malloc(sizeof(t_cir_lst));
	if (new_node == 0)
		return (0);
	new_node->content = content;
	new_node->next = new_node;
	new_node->prev = new_node;
	return (new_node);
}
