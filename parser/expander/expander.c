/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 02:14:52 by mypark            #+#    #+#             */
/*   Updated: 2022/04/06 22:27:31 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "info.h"
#include "parse_tree.h"
#include "expand_token.h"

static void	expand_tokens(\
	t_tokens *tks, \
	t_tokens *(*todo)(t_token *, t_exe_info *), \
	t_exe_info *info\
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
		ep_tks = todo(tk, info);
		merge_tokens(tks, ep_tks);
	}
	tk = tks->pop_head(tks);
	ep_tks = todo(tk, info);
	merge_tokens(tks, ep_tks);
}

static void	tour_tree_for_expansion(t_parsetree_node *node, t_exe_info *info)
{
	if (node == NULL || node->tokens == NULL || node->tokens->head == NULL)
		return ;
	if (node->type == TOKENS)
	{
		if (node->parent == NULL || node->parent->type != NODE_HRD)
		{
			expand_tokens(node->tokens, expand_token_env, info);
			expand_tokens(node->tokens, expand_token_wildcard, info);
		}
		expand_tokens(node->tokens, expand_token_quote, info);
	}
	tour_tree_for_expansion(node->left, info);
	tour_tree_for_expansion(node->right, info);
}

void	expander(t_parsetree_node *node, t_exe_info *info)
{
	tour_tree_for_expansion(node, info);
}
