/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_parsetree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:18:24 by mypark            #+#    #+#             */
/*   Updated: 2022/03/23 15:59:14 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "parse_tree.h"

void	print_parsetree_node(t_parsetree_node *node, int *cnt)
{
	printf("= %02d =======================================================\n", (*cnt)++);
	printf("myaddr : %p \n", node);
	printf("parent : %p \n", node->parent);
	printf("left   : %p \t", node->left);
	printf("right  : %p \n", node->right);
	printf("parsed : %d \n", node->parsed);
	print_tokens(node->tokens);
	printf("============================================================\n");
}

void	print_parsetree(t_parsetree_node *node, int *cnt)
{
	if (node->left)
		print_parsetree(node->left, cnt);
	print_parsetree_node(node, cnt);
	if (node->right)
		print_parsetree(node->right, cnt);
}
