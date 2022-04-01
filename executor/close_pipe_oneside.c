/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_pipe_oneside.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 21:16:13 by mypark            #+#    #+#             */
/*   Updated: 2022/04/01 21:16:39 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe_tree.h"
#include "libft.h"
#include "strict.h"

void	close_pipe_oneside(t_exetree_node *parent, t_exetree_node *exe_node, t_exe_info *info)
{
	int	*p;
	
	if (parent != NULL && parent->type == EXE_PIPE && parent->right == exe_node)
	{
		p = ft_lstlast(info->pipes)->content;
		strict_close(p[1]);
		p[1] = -1;
	}
	if (parent != NULL && parent->type == EXE_PIPE && parent->left == exe_node)
	{
		p = ft_lstlast(info->pipes)->content;
		strict_close(p[0]);
		p[0] = -1;
	}
}