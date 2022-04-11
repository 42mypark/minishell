/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:51:52 by mypark            #+#    #+#             */
/*   Updated: 2022/04/12 03:40:13 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "libft.h"
#include "expansion_record.h"
#include "error.h"
#include "strict.h"
#include "constant.h"
#include <stdlib.h>

void	free_token(void *token)
{
	t_token	*tk;

	tk = (t_token *)token;
	free_expansion_record(tk->expansion_record);
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

	tk = strict_malloc(sizeof(t_token), 1);
	if (tk == FT_NULL)
		return (FT_NULL);
	tk->content = ft_strdup(content);
	tk->type = type;
	tk->expansion_record = FT_NULL;
	return (tk);
}

t_tokens	*new_tokens(void)
{
	t_tokens	*tks;

	tks = new_deque();
	if (tks == FT_NULL)
		print_malloc_error();
	return (tks);
}

int	token_type_cmp(void *a, void *b)
{
	t_token	*tk_a;
	t_token	*tk_b;

	tk_a = (t_token *)a;
	tk_b = (t_token *)b;
	return (tk_a->type - tk_b->type);
}
