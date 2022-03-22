/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:18:24 by mypark            #+#    #+#             */
/*   Updated: 2022/03/22 23:59:30 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

char	*enum_token_to_str(enum e_token type)
{
	if (type == STR)
		return ("STR");
	if (type == IRD)
		return ("IRD");
	if (type == ORD)
		return ("ORD");
	if (type == HRD)
		return ("HRD");
	if (type == ARD)
		return ("ARD");
	if (type == PIPE)
		return ("PIPE");
	if (type == AND)
		return ("AND");
	if (type == OR)
		return ("OR");
	if (type == LPT)
		return ("LPT");
	if (type == RPT)
		return ("RPT");
	return ("INVALID");
}


void	print_tokens(t_tokens *tks)
{
	t_tokens_node	*curr;
	t_token			*tk;

	if (tks == NULL)
	{
		printf("TOKENS NULL\n");
		return ;
	}
	curr = tks->head;
	while (curr != tks->tail)
	{
		tk = curr->content;
		printf("token type : %s \t", enum_token_to_str(tk->type));
		printf("token content : %s \n", tk->content);
		curr = curr->next;
	}
	tk = curr->content;
	printf("token type : %s \t", enum_token_to_str(tk->type));
	printf("token content : %s \n", tk->content);
}
