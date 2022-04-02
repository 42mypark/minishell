/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_expander_actions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 02:55:07 by mypark            #+#    #+#             */
/*   Updated: 2022/04/02 16:03:15 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_expander.h"
#include "token.h"
#include "utils.h"

int	env_expander_chars(\
	t_env_expander *envexp, \
	char input\
)
{
	if (input == '$')
		return (set_state((int *)&envexp->state, E_EXPAND));
	push_buffer(envexp->buf, input);
	if (input == '\'')
		return (set_state((int *)&envexp->state, E_SINGLE_QUOTE));
	if (input == '\"')
		return (set_state((int *)&envexp->state, E_DOUBLE_QUOTE));
	return (0);
}

int	env_expander_double_quote(\
	t_env_expander *envexp, \
	char input\
)
{
	if (input == '$')
		return (set_state((int *)&envexp->state, E_DQ_EXPAND));
	push_buffer(envexp->buf, input);
	if (input == '\"')
		return (set_state((int *)&envexp->state, E_CHARS));
	return (0);
}

int	env_expander_single_quote(\
	t_env_expander *envexp, \
	char input\
)
{
	push_buffer(envexp->buf, input);
	if (input == '\'')
		return (set_state((int *)&envexp->state, E_CHARS));
	return (0);
}
