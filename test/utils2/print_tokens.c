/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:18:24 by mypark            #+#    #+#             */
/*   Updated: 2022/03/26 22:18:42 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "ep_rec.h"

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
	if (type == EXPANDED_STR)
		return ("EXPANDED_STR");
	return ("INVALID");
}


void	print_tokens(t_tokens *tks)
{
	t_tokens_node	*curr;
	t_token			*tk;
	t_ep_rec		*curr_ep;
	t_ep_range		*ep_range;

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
		printf("token content : %-20s ", tk->content);
		printf("token ep_rec : %-10p ", tk->ep_rec);
		curr_ep = tk->ep_rec;
		while (curr_ep)
		{
			ep_range = curr_ep->content;
			printf("token ep_range : %-10p ", ep_range);
			if (ep_range == NULL)
				break;
			printf("\t ep_start : %d \t ep_end : %d ", ep_range->start, ep_range->end);
			curr_ep = curr_ep->next;
		}
		printf("\n");
		curr = curr->next;
	}
	tk = curr->content;
	printf("token type : %-10s \t", enum_token_to_str(tk->type));
	printf("token content : %-20s ", tk->content);
	curr_ep = tk->ep_rec;
	while (curr_ep)
	{
		ep_range = curr_ep->content;
		if (ep_range == NULL)
			break;
		printf("\t ep_start : %d \t ep_end : %d ", ep_range->start, ep_range->end);
		curr_ep = curr_ep->next;
	}
	printf("\n");
}
