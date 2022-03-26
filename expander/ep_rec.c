/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ep_rec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 20:01:45 by mypark            #+#    #+#             */
/*   Updated: 2022/03/26 21:12:17 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ep_rec.h"
#include "libft.h"

t_ep_range	*new_ep_range(int s, int e)
{
	t_ep_range	*range;

	range = malloc(sizeof(t_ep_range));
	range->start = s;
	range->end = e;
	return (range);
}

void	free_ep_range(void *ep_range)
{
	t_ep_range *rec;

	rec = (t_ep_range *)ep_range;
	free(rec);
}

void	ep_rec_add_back(t_ep_rec **ep_rec, t_ep_range *content)
{
	ft_lstadd_back(ep_rec, ft_lstnew(content));
}

void	free_ep_rec(t_ep_rec **ep_rec)
{
	ft_lstclear(ep_rec, free_ep_range);
}

t_ep_range	*dup_ep_range(void *content)
{
	t_ep_range	*src;
	t_ep_range	*dst;

	src = (t_ep_range *)content;
	dst = new_ep_range(src->start, src->end);
	return (dst);
}

t_ep_rec	*dup_ep_rec(t_ep_rec *ep_rec)
{
	return (ft_lstdup(ep_rec, dup_ep_range));
}