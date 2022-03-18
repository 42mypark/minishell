/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 02:41:02 by mypark            #+#    #+#             */
/*   Updated: 2022/03/15 16:58:19 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include "../cir_lst/cir_lst.h"

typedef t_cir_lst t_stack_node;

typedef struct s_stack
{
	t_stack_node	*top;
	t_stack_node	*(*pop)(struct s_stack *);
	void			(*push)(struct s_stack *, t_stack_node *);
}				t_stack;

t_stack			*new_stack();
void			free_stack(t_stack *st, void (*del)(void *));
t_stack_node	*new_stack_node(void *content);

#endif
