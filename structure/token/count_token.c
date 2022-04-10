/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:44:55 by mypark            #+#    #+#             */
/*   Updated: 2022/04/10 18:22:55 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

int	count_token(t_tokens *tks)
{
	int				cnt;
	t_tokens_node	*curr;

	if (tks == 0 || tks->head == 0)
		return (0);
	cnt = 1;
	curr = tks->head;
	while (curr != tks->tail)
	{
		cnt++;
		curr = curr->next;
	}
	return (cnt);
}
