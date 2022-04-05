/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_exetree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:18:24 by mypark            #+#    #+#             */
/*   Updated: 2022/04/05 15:54:27 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "exe_tree.h"

void	print_err_info(t_err_info *info)
{
	if (info == NULL)
	{
		printf("err    : NULL\n");
		return ;
	}
	printf("err    :\n");
	printf("\t msg         = %s \n",info->msg);
	printf("\t exit status = %d \n",info->exit_status);
}

void	print_cmd_info(t_cmd_info *info)
{
	if (info == NULL)
	{
		printf("cmd    : NULL\n");
		return ;
	}
	printf("cmd    : %s\n", info->cmd);
	printf("arg    :\n");
	print_splited(info->args);
}

char *enum_exetree_node_to_str(enum e_exetree_node type)
{
	if (type == EXE_REDIR)
		return ("EXE_REDIR");
	if (type == EXE_PIPE)
		return ("EXE_PIPE");
	if (type == EXE_AND)
		return ("EXE_AND");
	if (type == EXE_OR)
		return ("EXE_OR");
	return ("EXE_ERROR");
}

void	print_exetree_node(t_exetree_node *node, int *cnt)
{
	printf("= %02d =======================================================\n", \
			(*cnt)++);
	printf("myaddr : %p \n", node);
	printf("parent : %p \n", node->parent);
	printf("left   : %p \t", node->left);
	printf("right  : %p \n", node->right);
	printf("type   : %s \n", enum_exetree_node_to_str(node->type));
	printf("fd[0]   : %d \n", node->fd[0]);
	printf("fd[1]  : %d \n", node->fd[1]);
	print_cmd_info(node->cmd);
	print_err_info(node->err);
	printf("============================================================\n");
}

void	print_exetree(t_exetree_node *node, int *cnt)
{
	if (node->left)
		print_exetree(node->left, cnt);
	print_exetree_node(node, cnt);
	if (node->right)
		print_exetree(node->right, cnt);
}
