/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_unexpected_token.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:46:50 by mypark            #+#    #+#             */
/*   Updated: 2022/04/10 17:42:22 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "strict.h"
#include "syntax.h"
#include "token.h"
#include "utils.h"

static int	check_head_tail(t_tokens *tks, int **syn_tb)
{
	t_token	*tk_curr;

	tk_curr = tks->head->content;
	if (is_bool(tk_curr->content[0]))
	{
		free_syntax_table(syn_tb);
		print_unexpected_token(tk_curr->content);
		return (1);
	}
	tk_curr = tks->tail->content;
	if (is_bool(tk_curr->content[0]) \
		|| is_redir(tk_curr->content[0]))
	{
		free_syntax_table(syn_tb);
		print_unexpected_token("newline");
		return (1);
	}
	return (0);
}

static int	check_unexpect_tk(enum e_token prev, enum e_token curr, \
							int **syn_tb, char *content)
{
	if (syn_tb[prev][curr] == 0)
	{
		free_syntax_table(syn_tb);
		print_unexpected_token(content);
		return (1);
	}
	return (0);
}

int	syntax_unexpected_token(t_tokens *tks)
{
	t_tokens_node	*curr;
	t_token			*tk_c;
	t_token			*tk_p;
	t_token			*tk_n;
	int				**syn_tb;

	syn_tb = get_syntax_table();
	if (check_head_tail(tks, syn_tb))
		return (1);
	curr = tks->head;
	while (curr != tks->tail)
	{
		tk_c = curr->content;
		tk_n = curr->next->content;
		tk_p = curr->prev->content;
		if (check_unexpect_tk(tk_c->type, tk_n->type, syn_tb, tk_n->content))
			return (1);
		if (curr != tks->head \
		&& check_unexpect_tk(tk_p->type, tk_c->type, syn_tb, tk_c->content))
			return (1);
		curr = curr->next;
	}
	free_syntax_table(syn_tb);
	return (0);
}
