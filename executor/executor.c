/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 22:11:07 by mypark            #+#    #+#             */
/*   Updated: 2022/04/08 20:12:58 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe_tree.h"
#include "parse_tree.h"
#include "execution.h"
#include "fdctrl.h"
#include "redirection.h"

#include "test.h"

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
	int			cnt = 0;

	exe_tree = make_exetree(parse_tree, info);
	free_parsetree(parse_tree);
	if (info->last_exit == 131)
	{
		close_all_fd(exe_tree, info);
		info->last_exit = 1;
		return ;
	}
	//print_exetree(exe_tree, &cnt);
	printf("\n***** cmd result *****\n");
	info->last_exit = execute_node(exe_tree, fd, info);
	free_exetree(exe_tree);
}
