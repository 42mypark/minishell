/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 02:14:52 by mypark            #+#    #+#             */
/*   Updated: 2022/03/24 02:31:45 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

t_tokens	*expand_token(t_token *tk, void (*todo)(t_tokens *, char *, char **), char **envp)
{
	t_tokens	*tks;
	char		*str;

	str = tk->content;
	free(tk);
	tks = new_tokens();
	todo(tks, str, envp);
	return (tks);
}
