/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_expander.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 02:06:59 by mypark            #+#    #+#             */
/*   Updated: 2022/04/11 01:34:49 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "strict.h"
#include "exe_tree.h"
#include "env_expander_actions.h"
#include "env_expander.h"
#include "expansion_record.h"

static void	init_env_expander(\
	t_env_expander *envexp, \
	t_tokens *tks, \
	char ***envp\
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

static int	is_only_dollar(t_env_expander *envexp, char *str, t_tokens *tks)
{
	if (is_same(str, "$"))
	{
		push_buffer_str(envexp->buf, str);
		issue_token(tks, envexp->buf);
		return (1);
	}
	return (0);
}

static int	is_exit_expansion(\
	t_env_expander *envexp, \
	char *str, \
	t_tokens *tks, \
	t_exe_info *info\
)
{
	char	*exit_status;

	if (is_same(str, "$?"))
	{
		exit_status = ft_itoa(info->last_exit);
		push_buffer_str(envexp->buf, exit_status);
		issue_token(tks, envexp->buf);
		free(exit_status);
		return (1);
	}
	return (0);
}

void	env_expander(t_tokens *tks, char *str, t_exe_info *info)
{
	t_env_expander		envexp;
	t_expansion_range	*range;

	init_env_expander(&envexp, tks, &info->envp);
	if (is_only_dollar(&envexp, str, tks) \
	|| is_exit_expansion(&envexp, str, tks, info))
	{
		reset_env_expander(&envexp);
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
