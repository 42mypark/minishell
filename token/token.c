/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:51:52 by mypark            #+#    #+#             */
/*   Updated: 2022/03/26 20:49:25 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "libft.h"
#include "ep_rec.h"
#include <stdlib.h>

void	free_token(void *token)
{
	t_token	*tk;

	tk = (t_token *)token;
	free_ep_rec(tk->ep_rec);
	free(tk->content);
	free(tk);
}

void	free_tokens(t_tokens *tks)
{
	free_deque(tks, free_token);
}

t_token	*new_token(enum e_token type, char *content)
{
	t_token	*tk;

	tk = malloc(sizeof(t_token));
	if (tk == NULL)
		return (NULL);
	tk->content = ft_strdup(content);
	tk->type = type;
	tk->ep_rec = NULL;
	return (tk);
}

t_tokens	*new_tokens(void)
{
	//need :  null check && error catch !!
	return (new_deque());
}

int	token_type_cmp(void *a, void *b)
{
	t_token	*tk_a;
	t_token	*tk_b;

	tk_a = (t_token *)a;
	tk_b = (t_token *)b;
	return (tk_a->type - tk_b->type);
}
