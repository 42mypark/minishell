/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 22:11:07 by mypark            #+#    #+#             */
/*   Updated: 2022/04/08 05:43:15 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe_tree.h"
#include "error.h"
#include "executor.h"

static int	exe_error(t_exetree_node *exnode, t_exe_info *info)
{
	close_unused_pipe(exnode, info);
	close_inout_fd(exnode);
	print_strerror("file", (char *)exnode->err->msg);
	if (exnode->parent && exnode->parent->type == EXE_PIPE)
		exit(exnode->err->exit_status);
	return (exnode->err->exit_status);
}

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

static void	close_all_fd(t_exetree_node *exnode, t_exe_info *info)
{
	t_pipelines	*curr;

	if (exnode == NULL)
		return ;
	if (exnode->left)
		close_all_fd(exnode->left, info);
	if (exnode->right)
		close_all_fd(exnode->right, info);
	if (exnode->pls)
	{
		curr = exnode->pls;
		while (curr)
		{
			close_all_fd(curr->content, info);
			curr = curr->next;
		}
	}
	if (exnode->type == EXE_REDIR)
		close_inout_fd(exnode);}

void	executor(t_exetree_node *exnode, t_exe_info *info)
{
	int	fd[2];
	fd[0] = 0;
	fd[1] = 1;
	if (info->last_exit == 131)
	{
		close_all_fd(exnode, info);
		info->last_exit = 1;
		return ;
	}
	info->last_exit = execute_node(exnode, fd, info);
}
