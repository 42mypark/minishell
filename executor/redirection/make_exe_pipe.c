/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_exe_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:54:46 by mypark            #+#    #+#             */
/*   Updated: 2022/04/22 08:26:07 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirection.h"

void	make_exe_pipe(\
	t_parsetree_node *p_nd, \
	t_exetree_node *e_nd, \
	t_exe_info *info\
)
{
	if (p_nd->type == NODE_PIPE && p_nd->left)
		make_exe_pipe(p_nd->left, e_nd, info);
	if (p_nd->type == NODE_PIPE && p_nd->right)
		make_exe_pipe(p_nd->right, e_nd, info);
	if (p_nd->type != NODE_PIPE)
		ft_lstadd_back(&e_nd->pipelines, \
						ft_lstnew(make_exetree_node(e_nd, p_nd, info)));
}
