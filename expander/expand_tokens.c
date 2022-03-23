/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 02:10:40 by mypark            #+#    #+#             */
/*   Updated: 2022/03/24 02:31:48 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_tree.h"

void expand_tokens(t_tokens *tks, void (*todo)(t_tokens *, char *, char **), char **envp)
{
	t_tokens		*ep_tks;
	t_tokens_node	*last;
	t_token			*tk;

	last = tks->tail;
	while(tks->head != last)
	{
		tk = tks->pop_head(tks);
		ep_tks = expand_token(tk, todo);
		merge_tokens(tks, ep_tks);
	}
	tk = tks->pop_head(tks);
	ep_tks = expand_token(tk, todo);
	merge_tokens(tks, ep_tks);
}
