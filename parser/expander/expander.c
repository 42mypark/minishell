/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 02:14:52 by mypark            #+#    #+#             */
/*   Updated: 2022/04/06 18:29:11 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "parse_tree.h"
#include "expand_token.h"

static void	expand_tokens(\
	t_tokens *tks, \
	t_tokens *(*todo)(t_token *, char **), \
	char **envp\
)
{
	t_tokens		*ep_tks;
	t_tokens_node	*last;
	t_token			*tk;

	if (tks->head == NULL)
		return ;
	last = tks->tail;
	while (tks->head != last)
	{
		tk = tks->pop_head(tks);
		ep_tks = todo(tk, envp);
		merge_tokens(tks, ep_tks);
	}
	tk = tks->pop_head(tks);
	ep_tks = todo(tk, envp);
	merge_tokens(tks, ep_tks);
}

static void	tour_tree_for_expansion(t_parsetree_node *node, char **envp)
{
	if (node == NULL || node->tokens == NULL || node->tokens->head == NULL)
		return ;
	if (node->type == TOKENS)
	{
		if (node->parent == NULL || node->parent->type != NODE_HRD)
		{
			expand_tokens(node->tokens, expand_token_env, envp);
			expand_tokens(node->tokens, expand_token_wildcard, envp);
		}
		expand_tokens(node->tokens, expand_token_quote, envp);
	}
	tour_tree_for_expansion(node->left, envp);
	tour_tree_for_expansion(node->right, envp);
}

void	expander(t_parsetree_node *node, char **envp)
{
	tour_tree_for_expansion(node, envp);
}
