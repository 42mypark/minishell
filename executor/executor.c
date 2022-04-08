/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 22:11:07 by mypark            #+#    #+#             */
/*   Updated: 2022/04/08 17:21:32 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe_tree.h"
#include "parse_tree.h"
#include "execution.h"
#include "redirection.h"

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
	if (exnode->pipelines)
	{
		curr = exnode->pipelines;
		while (curr)
		{
			close_all_fd(curr->content, info);
			curr = curr->next;
		}
	}
	if (exnode->type == EXE_REDIR)
		close_myinout_fd(exnode);
}

void	executor(t_parsetree_node *parse_tree, t_exe_info *info)
{
	t_exetree_node	*exe_tree;
	static int		fd[2] = { 0, 1 };

	exe_tree = make_exetree(parse_tree, info);
	free_parsetree(parse_tree);
	if (info->last_exit == 131)
	{
		close_all_fd(exe_tree, info);
		info->last_exit = 1;
		return ;
	}
	info->last_exit = execute_node(exe_tree, fd, info);
	free_exetree(exe_tree);
}
