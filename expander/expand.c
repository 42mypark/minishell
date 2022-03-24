/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 02:14:52 by mypark            #+#    #+#             */
/*   Updated: 2022/03/24 22:48:47 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "parse_tree.h"
#include "test.h"

static t_tokens	*expand_token(t_token *tk, void (*todo)(t_tokens *, char *, char **), char **envp)
{
	t_tokens	*tks;
	char		*str;

	tks = new_tokens();
	todo(tks, tk->content, envp);
	if (tks->head == NULL)
		tks->push_tail(tks, tk);
	else
		free_token(tk);
	return (tks);
}

static void expand_tokens(t_tokens *tks, void (*todo)(t_tokens *, char *, char **), char **envp)
{
	t_tokens		*ep_tks;
	t_tokens_node	*last;
	t_token			*tk;

	last = tks->tail;
	while(tks->head != last)
	{
		tk = tks->pop_head(tks);
		ep_tks = expand_token(tk, todo, envp);
		merge_tokens(tks, ep_tks);
	}
	tk = tks->pop_head(tks);
	ep_tks = expand_token(tk, todo, envp);
	merge_tokens(tks, ep_tks);
}

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
