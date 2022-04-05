/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_range.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:14:46 by mypark            #+#    #+#             */
/*   Updated: 2022/04/05 13:14:48 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion_record.h"
#include "libft.h"
#include "strict.h"

t_expansion_range	*new_expansion_range(int start, int end)
{
	t_expansion_range	*range;

	range = strict_malloc(sizeof(t_expansion_range), 1);
	range->start = start;
	range->end = end;
	return (range);
}

void	free_expansion_range(void *expansion_range)
{
	t_expansion_range	*rec;

	rec = (t_expansion_range *)expansion_range;
	free(rec);
}

void	*dup_expansion_range(void *content)
{
	t_expansion_range	*src;
	t_expansion_range	*dst;

	src = (t_expansion_range *)content;
	dst = new_expansion_range(src->start, src->end);
	return (dst);
}
