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

#include "exe_tree.h"
#include "libft.h"
#include "strict.h"
#include "exe_tree.h"

void	close_unused_pipe(t_exetree_node *exnode, t_exe_info *info)
{
	if (exnode->parent && exnode->parent->type == EXE_PIPE \
		&& info->pipefd_unused != -1)
		strict_close(info->pipefd_unused);
	info->pipefd_unused = -1;
}
