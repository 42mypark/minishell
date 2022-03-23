/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 02:41:02 by mypark            #+#    #+#             */
/*   Updated: 2022/03/23 16:19:07 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include "../cir_lst/cir_lst.h"

typedef t_cir_lst	t_stack_node;

typedef struct s_stack
{
	t_stack_node	*top;
	void			*(*pop)(struct s_stack *);
	int				(*push)(struct s_stack *, void *);
}				t_stack;

t_stack			*new_stack(void);
void			free_stack(t_stack *st, void (*del)(void *));

#endif
