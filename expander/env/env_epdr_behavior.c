/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_epdr_behavior.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 02:59:21 by mypark            #+#    #+#             */
/*   Updated: 2022/03/24 03:29:54 by mypark           ###   ########.fr       */
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
}

t_env_epdr_state	env_epdr_double_quote(t_tokens *tks, t_buffer *buf, \
									char input, char **envp)
{
	if (input == '$')
		return (E_DQ_EXPAND);
	push_buffer(buf, input);
	if (input == '\"')
		return (E_CHARS);
}

t_env_epdr_state	env_epdr_single_quote(t_tokens *tks, t_buffer *buf, \
									char input, char **envp)
{
	push_buffer(buf, input);
	if (input == '\'')
		return (E_CHARS);
}
