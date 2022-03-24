/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_tour_tree.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 02:00:47 by mypark            #+#    #+#             */
/*   Updated: 2022/03/24 13:07:16 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_tree.h"

void	expand_tour_tree(t_parsetree_node *node, void (*todo)(t_tokens *, char *, char **), char **envp)
{
	t_token	*tk;

	if(node == NULL)
		return ;
	tk = node->tokens->head->content;
	if(tk->type == STR)
	 	expand_tokens(node->tokens, todo, envp);
	expand_tour_tree(node->left, todo, envp);
	expand_tour_tree(node->right, todo, envp);
}
