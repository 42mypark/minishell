/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 02:14:52 by mypark            #+#    #+#             */
/*   Updated: 2022/03/26 19:34:12 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "parse_tree.h"

static void expand_tokens(t_tokens *tks, t_tokens *(*todo)(t_token *, char **), char **envp)
{
	t_tokens		*ep_tks;
	t_tokens_node	*last;
	t_token			*tk;

	if (tks->head == NULL)
		return ;
	last = tks->tail;
	while(tks->head != last)
	{
		tk = tks->pop_head(tks);
		ep_tks = todo(tk, envp);
		merge_tokens(tks, ep_tks);
	}
	tk = tks->pop_head(tks);
	ep_tks = todo(tk, envp);
	merge_tokens(tks, ep_tks);
}

void	expand_tour_tree(t_parsetree_node *node, t_tokens *(*todo)(t_token *, char **), char **envp)
{
	if(node == NULL || node->tokens == NULL || node->tokens->head == NULL)
		return ;
	if(node->type == TOKENS)
	 	expand_tokens(node->tokens, todo, envp);
	expand_tour_tree(node->left, todo, envp);
	expand_tour_tree(node->right, todo, envp);
}
