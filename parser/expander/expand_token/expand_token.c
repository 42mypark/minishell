/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 02:14:52 by mypark            #+#    #+#             */
/*   Updated: 2022/04/22 08:15:11 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constant.h"
#include "expander.h"
#include "libft.h"

t_tokens	*expand_token_env(t_token *tk, t_exe_info *info)
{
	t_tokens	*tks;

	tks = new_tokens();
	if (ft_strchri(tk->content, '$') != -1)
	{
		env_expander(tks, tk->content, info);
		free_token(tk);
	}
	else
		tks->push_tail(tks, tk);
	return (tks);
}

t_tokens	*expand_token_wildcard(t_token *tk, t_exe_info *info)
{
	t_tokens	*tks;

	(void)info;
	tks = new_tokens();
	if (ft_strchri(tk->content, '*') != -1)
		wildcard_expander(tks, tk);
	if (tks->head == FT_NULL)
		tks->push_tail(tks, tk);
	else
		free_token(tk);
	return (tks);
}

t_tokens	*expand_token_quote(t_token *tk, t_exe_info *info)
{
	t_tokens	*tks;

	(void)info;
	tks = new_tokens();
	quote_remover(tks, tk);
	free_token(tk);
	return (tks);
}
