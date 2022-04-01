/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ep_rec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 20:01:45 by mypark            #+#    #+#             */
/*   Updated: 2022/04/01 15:04:58 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ep_rec.h"
#include "libft.h"
#include "error.h"
#include "strict.h"

t_ep_range	*new_ep_range(int start, int end)
{
	t_ep_range	*range;

	range = strict_malloc(sizeof(t_ep_range), 1);
	range->start = start;
	range->end = end;
	return (range);
}

void	free_ep_range(void *ep_range)
{
	t_ep_range	*rec;

	rec = (t_ep_range *)ep_range;
	free(rec);
}

void	ep_rec_add_back(t_ep_rec **ep_rec, t_ep_range *content)
{
	ft_lstadd_back(ep_rec, ft_lstnew(content));
}

void	free_ep_rec(t_ep_rec *ep_rec)
{
	ft_lstclear(&ep_rec, free_ep_range);
}

void	*dup_ep_range(void *content)
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
