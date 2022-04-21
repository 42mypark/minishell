/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:54:42 by mypark            #+#    #+#             */
/*   Updated: 2022/04/22 08:24:20 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	execute_node(t_exetree_node *exnode, int *parent_fd, t_exe_info *info)
{
	if (exnode->type == EXE_ERROR)
		return (exe_error(exnode, info));
	if (exnode->type == EXE_REDIR)
		return (exe_redir(exnode, parent_fd, info));
	if (exnode->type == EXE_PIPE)
		return (exe_pipe(exnode, parent_fd, info));
	if (exnode->type == EXE_AND)
		return (exe_and(exnode, parent_fd, info));
	if (exnode->type == EXE_OR)
		return (exe_or(exnode, parent_fd, info));
	return (0);
}
