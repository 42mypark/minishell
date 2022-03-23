/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 02:48:54 by mypark            #+#    #+#             */
/*   Updated: 2022/03/23 16:18:55 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdlib.h>

static void	*pop(struct s_stack *st)
{
	t_stack_node	*node;
	void			*content;

	node = cir_lstpop_front(&st->top);
	content = node->content;
	free(node);
	return (content);
}

static t_stack_node	*new_stack_node(void *content)
{
	return (cir_lstnew(content));
}

static int	push(t_stack *st, void *content)
{
	t_stack_node	*new;

	new = new_stack_node(content);
	if (new == NULL)
		return (0);
	cir_lstadd_front(&st->top, new);
	return (1);
}

t_stack	*new_stack(void)
{
	t_stack	*st;

	st = malloc(sizeof(t_stack));
	st->top = NULL;
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
