/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_expansion_record.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 07:12:59 by mypark            #+#    #+#             */
/*   Updated: 2022/04/22 07:13:01 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	print_expansion_range(t_expansion_range *range)
{
	if (range == NULL)
	{
		printf("range is NULL\n");
		return ;
	}
	printf("\tstart : %3d, end : %3d \n", range->start, range->end);
}

void	print_expansion_record(t_expansion_record *rec)
{
	t_expansion_record	*curr;

	curr = rec;
	if (curr == NULL)
	{
		printf("curr_rec : %p\n", curr);
		return ;
	}
	while (curr)
	{
		printf("curr_rec : %p\n", curr);
		print_expansion_range(curr->content);
		curr = curr->next;
	}
}
