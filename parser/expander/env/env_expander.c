/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_expander.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 02:06:59 by mypark            #+#    #+#             */
/*   Updated: 2022/04/06 18:32:31 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "strict.h"
#include "env_expander_actions.h"
#include "env_expander.h"
#include "expansion_record.h"
#include "test.h"

static void	init_env_expander(\
	t_env_expander *envexp, \
	t_tokens *tks, \
	char **envp\
)
{
	envexp->state = E_CHARS;
	envexp->actions[0] = env_expander_chars;
	envexp->actions[1] = env_expander_single_quote;
	envexp->actions[2] = env_expander_double_quote;
	envexp->actions[3] = env_expander_dollar;
	envexp->actions[4] = env_expander_dq_dollar;
	envexp->buf = strict_malloc(sizeof(t_buffer), 1);
	init_buffer(envexp->buf);
	envexp->tokens = tks;
	envexp->envp = envp;
}

static void	reset_env_expander(t_env_expander *envexp)
{
	reset_buffer(envexp->buf);
	free(envexp->buf);
}

void	env_expander(t_tokens *tks, char *str, char **envp)
{
	t_env_expander		envexp;
	t_expansion_range	*range;

	init_env_expander(&envexp, tks, envp);
	if (is_same(str, "$"))
	{
		push_buffer_str(envexp.buf, str);
		issue_token(tks, envexp.buf);
		return ;
	}
	while (*str)
	{
		envexp.actions[envexp.state](&envexp, *str);
		str++;
	}
	if (envexp.state == E_EXPAND)
	{
		envexp.actions[E_EXPAND](&envexp, '\0');
		range = new_expansion_range(envexp.buf->start, envexp.buf->len);
		expansion_record_add_back(&envexp.buf->expansion_record, range);
	}
	if (envexp.buf->len)
		issue_token(tks, envexp.buf);
	reset_env_expander(&envexp);
}
