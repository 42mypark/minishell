/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_unexpected_token.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:46:50 by mypark            #+#    #+#             */
/*   Updated: 2022/04/01 15:01:45 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "utils.h"
#include "error_utils.h"
#include "strict.h"
#include "test.h"

static int	**copy_table(const char (*table)[11])
{
	int	i;
	int	j;
	int	**syn_tb;

	syn_tb = strict_malloc(sizeof(int *), 11);
	i = -1;
	while (++i < 11)
	{
		syn_tb[i] = strict_malloc(sizeof(int), 11);
		j = -1;
		while (++j < 11)
			syn_tb[i][j] = (int) table[i][j];
	}
	return (syn_tb);
}

static int	**get_syntax_table(void)
{
	static const char	table[11][11] = {
									{1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0},
									{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
									{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
									{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
									{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
									{1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0},
									{1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0},
									{1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0},
									{1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0},
									{0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0},
									{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
									};

	return (copy_table(table));
}

static void	free_syntax_table(int **syn_tb)
{
	int	i;

	i = 0;
	while (i < 11)
		free(syn_tb[i++]);
	free(syn_tb);
}

static void	check_head_tail(t_tokens *tks)
{
	t_token	*tk_curr;

	tk_curr = tks->head->content;
	if (is_bool(tk_curr->content[0]))
		print_unexpected_token(tks, tk_curr->content);
	tk_curr = tks->tail->content;
	if (is_bool(tk_curr->content[0]) \
		|| is_redir(tk_curr->content[0]))
		print_unexpected_token(tks, "newline");
}

void	syntax_unexpected_token(t_tokens *tks)
{
	t_tokens_node	*curr;
	t_token			*tk_curr;
	t_token			*tk_prev;
	t_token			*tk_next;
	int				**syn_tb;

	syn_tb = get_syntax_table();
	check_head_tail(tks);
	curr = tks->head;
	while (curr != tks->tail)
	{
		tk_curr = curr->content;
		tk_next = curr->next->content;
		tk_prev = curr->prev->content;
		if (syn_tb[tk_curr->type][tk_next->type] == 0)
			print_unexpected_token(tks, tk_next->content);
		if (curr != tks->head && syn_tb[tk_prev->type][tk_curr->type] == 0)
			print_unexpected_token(tks, tk_curr->content);
		curr = curr->next;
	}
	free_syntax_table(syn_tb);
}
