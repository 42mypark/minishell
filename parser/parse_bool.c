/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:38:17 by mypark            #+#    #+#             */
/*   Updated: 2022/03/22 22:23:42 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_utils.h"
#include "test.h"

int	parse_bool(t_parsetree_node *pt_node)
{
	t_tokens		*tks;
	t_token			*tk;
	t_tokens_node	*curr;
	t_tokens		*l_tks;
	t_tokens		*r_tks;

	tks = pt_node->tokens;
	curr = tks->tail;
	while (curr != tks->head)
	{
		pass_parenthesis_forward(curr);
		tk = curr->content;
		if (tk->type == AND || tk->type == OR)
		{
			printf("find bool!\n");
			r_tks = cut_tokens_back(tks, curr);
			l_tks = cut_tokens_front(tks, curr);
			pt_node->right = new_parsetree_node(r_tks, pt_node);
			pt_node->left = new_parsetree_node(l_tks, pt_node);
			print_tokens(r_tks);
			print_tokens(l_tks);
			print_parsetree_node(pt_node);
			print_parsetree_node(pt_node->left);
			print_parsetree_node(pt_node->right);
			pt_node->parsed = 1;
			return (1);
		}
		curr = curr->prev;
	}
	return (0);
}
