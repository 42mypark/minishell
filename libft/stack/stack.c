/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 02:48:54 by mypark            #+#    #+#             */
/*   Updated: 2022/03/15 16:58:08 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdlib.h>

static t_stack_node	*pop(struct s_stack *st)
{
	return (cir_lstpop_front(&st->top));
}

static void	push(t_stack *st, t_stack_node *new)
{
	cir_lstadd_front(&st->top, new);
}

t_stack_node	*new_stack_node(void *content)
{
	return (cir_lstnew(content));
}

t_stack	*new_stack()
{
	t_stack	*st;

	st = malloc(sizeof(t_stack));
	if (st == NULL)
		return (NULL);
	st->pop = pop;
	st->push = push;
	return (st);
}

void	free_stack(t_stack *st, void (*del)(void *))
{
	cir_lstclear(&st->top, del);
	free(st);
}
