/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:51:52 by mypark            #+#    #+#             */
/*   Updated: 2022/03/18 16:01:28 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include <stdlib.h>

void	free_token(void *token)
{
	t_token	*tk;
	
	tk = (t_token *)token;
	free(tk->content);
	free(tk);
}

void		free_tokens(t_tokens *tks)
{
	free_deque(tks, free_token);
}

t_token		*new_token(enum e_token type, char *content)
{
	t_token	*tk;

	tk = malloc(sizeof(t_token));
	if (tk == NULL)
		return (NULL);
	tk->content = ft_strdup(content);
	tk->type = type;
	return (tk);
}

t_tokens	*new_tokens()
{
	return (new_deque());
}