/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_unused_pipe.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 21:16:13 by mypark            #+#    #+#             */
/*   Updated: 2022/04/01 21:16:39 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strict.h"
#include "exe_tree.h"
#include "info.h"

void	close_unused_pipe(t_exetree_node *exnode, t_exe_info *info)
{
	int	is_parent_pipe;
	int	is_there_unsed_pipe;

	is_parent_pipe = exnode->parent && exnode->parent->type == EXE_PIPE;
	is_there_unsed_pipe =  is_parent_pipe && info->pipefd_unused != -1;
	if (is_there_unsed_pipe)
		strict_close(info->pipefd_unused);
	info->pipefd_unused = -1;
}
