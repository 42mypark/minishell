/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 22:11:07 by mypark            #+#    #+#             */
/*   Updated: 2022/04/01 20:34:29 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe_tree.h"
#include "error.h"
#include "executor.h"

static void	exe_error(t_exetree_node *exe_node)
{
	print_strerror("ERROR", (char *)exe_node->err->msg);
	exit(exe_node->err->exit_status);
}

void	execute_node(t_exetree_node *exe_node, int parent_infd, int parent_outfd, t_exe_info *info)
{
	if (exe_node->type == EXE_ERROR)
		exe_error(exe_node);
	if (exe_node->type == EXE_REDIR)
		exe_redir(exe_node, parent_infd, parent_outfd, info);
	if (exe_node->type == EXE_PIPE)
		exe_pipe(exe_node, parent_infd, parent_outfd, info);
	if (exe_node->type == EXE_AND)
		exe_and(exe_node, parent_infd, parent_outfd, info);
	if (exe_node->type == EXE_OR)
		exe_or(exe_node, parent_infd, parent_outfd, info);
}

void	executor(t_exetree_node *exe_node, t_exe_info *info)
{
	execute_node(exe_node, 0, 1, info);
}