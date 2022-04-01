/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_and.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 23:46:16 by mypark            #+#    #+#             */
/*   Updated: 2022/04/01 21:23:07 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe_tree.h"
#include "info.h"
#include "executor.h"
#include "strict.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "test.h"

void	exe_and(t_exetree_node *exe_node, int parent_infd, int parent_outfd, t_exe_info *info)
{
	// int a = 0;
	
	if (exe_node->infd == 0)
		exe_node->infd = parent_infd;
	if (exe_node->outfd == 1)
		exe_node->outfd = parent_outfd;
	
	close_pipe_oneside(exe_node->parent, exe_node, info);
	if (exe_bool_child(exe_node->left, exe_node->infd, exe_node->outfd, info) == 0)
		exit(1) ;
	// printf("\n### in and node ###\n");
	// print_exetree_node(exe_node, &a);
	if (exe_bool_child(exe_node->right, exe_node->infd, exe_node->outfd, info) == 0)
		exit(1);
	exit(0);
}
