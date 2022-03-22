/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_incorrect_pairs.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 01:27:09 by mypark            #+#    #+#             */
/*   Updated: 2022/03/23 02:47:05 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "error_utils.h"

static int	is_correct_parenthese(t_tokens *tks)
{
	t_tokens_node	*curr;
	t_token			*tk;
	int				cnt;

	curr = tks->head;
	cnt = 0;
	while (curr != tks->tail)
	{
		tk = curr->content;
		if (tk->type == LPT)
			cnt++;
		if (tk->type == RPT)
			cnt--;
		if (cnt < 0)
			return (0);
		curr = curr->next;
	}
	tk = tks->tail->content;
	if (tk->type == LPT)
		cnt++;
	if (tk->type == RPT)
		cnt--;
	if (cnt != 0)
		return (0);
	return (1);
}

static int	is_ok_quotes(char *str)
{
	int	dq;
	int	sq;

	dq = 0;
	sq = 0;
	while (*str)
	{
		if (!dq && *str == '\'')
			sq = !sq;
		if (!sq && *str == '\"')
			dq = !dq;
		str++;
	}
	if (sq || dq)
		return (0);
	return (1);
}

static int	is_correct_quotes(t_tokens *tks)
{
	t_tokens_node	*curr;
	t_token			*tk;
	int				cnt;

	curr = tks->head;
	cnt = 0;
	while (curr != tks->tail)
	{
		tk = curr->content;
		if (tk->type == STR && !is_ok_quotes(tk->content))
			return (0);
		curr = curr->next;
	}
	tk = tks->tail->content;
	if (tk->type == STR && !is_ok_quotes(tk->content))
		return (0);
	return (1);
}

void	syntax_incorrect_pairs(t_tokens *tks)
{
	if (!is_correct_parenthese(tks))
		print_incorrect_pairs(tks, "parenthese");
	if (!is_correct_quotes(tks))
		print_incorrect_pairs(tks, "quotes");
}
