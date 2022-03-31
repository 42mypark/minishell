/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 02:14:52 by mypark            #+#    #+#             */
/*   Updated: 2022/03/31 21:35:09 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "parse_tree.h"

void	env_expander(t_tokens *tks, char *str, char **envp);
void	wildcard_expander(t_tokens *tks, t_token *tk, char **envp);
void	quote_remover(t_tokens *tks, t_token *tk);

static t_tokens	*expand_token_env(t_token *tk, char **envp)
{
	t_tokens	*tks;

	tks = new_tokens();
	env_expander(tks, tk->content, envp);
	free_token(tk);
	return (tks);
}

static t_tokens	*expand_token_wildcard(t_token *tk, char **envp)
{
	t_tokens	*tks;

	tks = new_tokens();
	wildcard_expander(tks, tk, envp);
	if (tks->head == NULL)
		tks->push_tail(tks, tk);
	else
		free_token(tk);
	return (tks);
}

static t_tokens	*expand_token_quote(t_token *tk, char **envp)
{
	t_tokens	*tks;

	envp++;
	tks = new_tokens();
	quote_remover(tks, tk);
	free_token(tk);
	return (tks);
}

static void	expand_tokens(t_tokens *tks, \
						t_tokens *(*todo)(t_token *, char **), char **envp)
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

void	expand_tour_tree(t_parsetree_node *node, char **envp)
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
	expand_tour_tree(node->left, envp);
	expand_tour_tree(node->right, envp);
}
