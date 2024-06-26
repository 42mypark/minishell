/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 22:11:07 by mypark            #+#    #+#             */
/*   Updated: 2022/04/12 03:42:45 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe_tree.h"
#include "parse_tree.h"
#include "execution.h"
#include "fdctrl.h"
#include "redirection.h"
#include "constant.h"
#include "interrupt.h"
#include <signal.h>

static void close_all_fd(t_exetree_node *exnode, t_exe_info *info)
{
	t_pipelines *curr;

	if (exnode == FT_NULL)
		return;
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

void executor(t_parsetree_node *parse_tree, t_exe_info *info)
{
	t_exetree_node *exe_tree;
	static int fd[2] = {0, 1};

	signal(SIGINT, ctrl_c2);
	exe_tree = make_exetree(parse_tree, info);
	free_parsetree(parse_tree);
	if (info->heredoc_fail)
	{
		close_all_fd(exe_tree, info);
		info->heredoc_fail = 0;
		return;
	}
	signal(SIGQUIT, ctrl_quit);
	info->last_exit = execute_node(exe_tree, fd, info);
	free_exetree(exe_tree);
}
