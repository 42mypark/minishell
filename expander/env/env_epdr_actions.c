/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_epdr_actions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 02:59:21 by mypark            #+#    #+#             */
/*   Updated: 2022/03/26 17:29:55 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_expander_utils.h"
#include "token.h"
#include "utils.h"

t_env_epdr_state	env_epdr_chars(t_tokens *tks, t_buffer *buf, \
									char input, char **envp)
{
	if (input == '$')
		return (E_EXPAND);
	push_buffer(buf, input);
	if (input == '\'')
		return (E_SINGLE_QUOTE);
	if (input == '\"')
		return (E_DOUBLE_QUOTE);
	return (E_CHARS);
}

t_env_epdr_state	env_epdr_double_quote(t_tokens *tks, t_buffer *buf, \
									char input, char **envp)
{
	if (input == '$')
		return (E_DQ_EXPAND);
	push_buffer(buf, input);
	if (input == '\"')
		return (E_CHARS);
	return (E_DOUBLE_QUOTE);
}

t_env_epdr_state	env_epdr_single_quote(t_tokens *tks, t_buffer *buf, \
									char input, char **envp)
{
	push_buffer(buf, input);
	if (input == '\'')
		return (E_CHARS);
	return (E_SINGLE_QUOTE);
}
