/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:18:24 by mypark            #+#    #+#             */
/*   Updated: 2022/04/08 16:23:04 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "expansion_record.h"

char	*enum_token_to_str(enum e_token type)
{
	if (type == TK_STR)
		return ("STR");
	if (type == TK_IRD)
		return ("IRD");
	if (type == TK_ORD)
		return ("ORD");
	if (type == TK_HRD)
		return ("HRD");
	if (type == TK_ARD)
		return ("ARD");
	if (type == TK_PIPE)
		return ("PIPE");
	if (type == TK_AND)
		return ("AND");
	if (type == TK_OR)
		return ("OR");
	if (type == TK_LPT)
		return ("LPT");
	if (type == TK_RPT)
		return ("RPT");
	if (type == TK_EXPANDED_STR)
		return ("EXPANDED_STR");
	if (type == TK_QUOTED_STR)
		return ("QUOTED_STR");
	return ("INVALID");
}

void	print_tokens(t_tokens *tks)
{
	t_tokens_node	*curr;
	t_token			*tk;

	if (tks == NULL || tks->head == NULL)
	{
		printf("TOKENS NULL or TOKENS HEAD NULL\n");
		return ;
	}
	curr = tks->head;
	while (curr != tks->tail)
	{
		tk = curr->content;
		printf("token type : %-10s \t", enum_token_to_str(tk->type));
		printf("token content : %-20s \n", tk->content);
		print_expansion_record(tk->expansion_record);
		printf("\n");
		curr = curr->next;
	}
	tk = curr->content;
	printf("token type : %-10s \t", enum_token_to_str(tk->type));
	printf("token content : %-20s \n", tk->content);
	print_expansion_record(tk->expansion_record);
	printf("\n");
}
