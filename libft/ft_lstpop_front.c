/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 19:30:35 by dha               #+#    #+#             */
/*   Updated: 2022/04/01 19:11:06 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstpop_front(t_list **head)
{
	t_list	*second;
	t_list	*first;

	if (head == 0 || *head == 0)
		return (0);
	second = (*head)->next;
	first = (*head);
	first->next = 0;
	(*head) = second;
	return (first);
}
