/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_to_splited.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:42:29 by mypark            #+#    #+#             */
/*   Updated: 2022/04/10 18:19:43 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "libft.h"
#include "error.h"
#include "strict.h"

char	**tokens_to_splited(t_tokens *tks)
{
	char			**splited;
	int				wc;
	t_tokens_node	*curr;
	t_token			*tk;

	wc = count_token(tks);
	splited = strict_malloc(sizeof(char *), (wc + 1));
	splited[wc] = 0;
	curr = tks->head;
	wc = 0;
	while (curr != tks->tail)
	{
		tk = curr->content;
		splited[wc++] = ft_strdup(tk->content);
		curr = curr->next;
	}
	if (tks->tail != 0)
	{
		tk = tks->tail->content;
		splited[wc++] = ft_strdup(tk->content);
	}
	return (splited);
}
