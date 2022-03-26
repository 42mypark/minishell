/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 21:40:33 by mypark            #+#    #+#             */
/*   Updated: 2022/03/26 21:09:16 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstdup(t_list *lst, void *(*dup)(void *))
{
	t_list	*new;

	if (lst == NULL)
		return (NULL);
	new = NULL;
	while (lst)
	{
		ft_lstadd_back(&new, dup(lst->content));
		lst = lst->next;
	}
	return (new);
}
