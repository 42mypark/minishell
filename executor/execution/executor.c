/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 22:11:07 by mypark            #+#    #+#             */
/*   Updated: 2022/04/07 01:11:48 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe_tree.h"
#include "error.h"
#include "executor.h"

static int	exe_error(t_exetree_node *exe_node)
{
	print_strerror("file", (char *)exe_node->err->msg);
	if (exe_node->parent && exe_node->parent->type == EXE_PIPE)
		exit(exe_node->err->exit_status);
	return (exe_node->err->exit_status);
}

int	execute_node(t_exetree_node *exe_node, int *parent_fd, t_exe_info *info)
{
	if (exe_node->type == EXE_ERROR)
		return (exe_error(exe_node));
	if (exe_node->type == EXE_REDIR)
		return (exe_redir(exe_node, parent_fd, info));
	if (exe_node->type == EXE_PIPE)
		return (exe_pipe(exe_node, parent_fd, info));
	if (exe_node->type == EXE_AND)
		return (exe_and(exe_node, parent_fd, info));
	if (exe_node->type == EXE_OR)
		return (exe_or(exe_node, parent_fd, info));
	return (0);
}

void	close_all_fd(t_exetree_node *exe_node, t_exe_info *info)
{
	if (exe_node == NULL)
		return ;
	if (exe_node->left)
		close_all_fd(exe_node->left, info);
	if (exe_node->right)
		close_all_fd(exe_node->right, info);
	if (exe_node->type == EXE_REDIR)
		close_fd(exe_node, info);
}

void	executor(t_exetree_node *exe_node, t_exe_info *info)
{
	int	fd[2];
	fd[0] = 0;
	fd[1] = 1;
	if (info->last_exit == 131)
	{
		close_all_fd(exe_node, info);
		info->last_exit = 1;
		return ;
	}
	info->last_exit = execute_node(exe_node, fd, info);
}
