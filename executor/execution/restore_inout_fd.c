/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restore_inout_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 02:31:21 by mypark            #+#    #+#             */
/*   Updated: 2022/04/06 17:30:47 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "strict.h"
#include "test.h"
#include "exe_tree.h"

static void	close_inout_fd(t_exetree_node *e_node)
{
	if (e_node->fd[0] != 0)
		strict_close(0);
	if (e_node->fd[1] != 1)
		strict_close(1);
}

void	restore_inout_fd(t_exetree_node *e_node)
{
	close_inout_fd(e_node);
	strict_dup2(4, 1);
	strict_dup2(3, 0);
}
