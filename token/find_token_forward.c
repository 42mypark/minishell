/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_token_forward.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:55:55 by mypark            #+#    #+#             */
/*   Updated: 2022/03/18 16:59:11 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

t_tokens_node	*find_token_forward(t_tokens_node *curr, enum e_token type)
{
	t_token	dummy;

	dummy.type = type;
	dummy.content = NULL;
	return (cir_lstfind_forward(curr, &dummy, token_type_cmp));
}