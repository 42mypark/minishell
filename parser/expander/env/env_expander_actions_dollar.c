/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_expander_actions_dollar.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 02:49:51 by mypark            #+#    #+#             */
/*   Updated: 2022/04/07 02:46:36 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_expander.h"
#include "expansion_record.h"
#include "token.h"
#include "utils.h"

static void	push_env_to_buffer(t_buffer *env_name, t_buffer *buf, char **envp)
{
	char				*env;
	int					start;
	t_expansion_range	*range;

	env = dupenv(env_name->space, envp);
	start = buf->len;
	push_buffer_str(buf, env);
	range = new_expansion_range(start, buf->len);
	expansion_record_add_back(&buf->expansion_record, range);
	free(env);
}

int	env_expander_dq_dollar(\
	t_env_expander *envexp, \
	char input\
)
{
	static t_buffer	env_name;

	if (input == '_' || ft_isalnum(input))
		push_buffer(&env_name, input);
	else
	{
		push_env_to_buffer(&env_name, envexp->buf, *envexp->envp);
		reset_buffer(&env_name);
		if (input == '$')
			return (0);
		push_buffer(envexp->buf, input);
		if (input == '\"')
			return (set_state((int *)&envexp->state, E_CHARS));
		return (set_state((int *)&envexp->state, E_DOUBLE_QUOTE));
	}
	return (0);
}

static int	pass_blank(char *str, int i)
{
	i++;
	while (str[i])
	{
		if (!is_blank(str[i]))
			break ;
		i++;
	}
	return (i);
}

static void	env_to_token(t_tokens *tks, t_buffer *buf, char *env)
{
	int					i;
	t_expansion_range	*range;

	i = 0;
	if (is_blank(env[0]))
	{
		if (buf->len)
			issue_token(tks, buf);
		i = pass_blank(env, i);
	}
	buf->start = buf->len;
	while (env[i])
	{
		if (is_blank(env[i]))
		{
			range = new_expansion_range(buf->start, buf->len);
			expansion_record_add_back(&buf->expansion_record, range);
			issue_token(tks, buf);
			i = pass_blank(env, i);
		}
		else
			push_buffer(buf, env[i++]);
	}
}

int	env_expander_dollar(\
	t_env_expander *envexp, \
	char input\
)
{
	static t_buffer	env_name;
	char			*env;

	if (input == '_' || ft_isalnum(input))
		push_buffer(&env_name, input);
	else
	{
		env = dupenv(env_name.space, *envexp->envp);
		env_to_token(envexp->tokens, envexp->buf, env);
		free(env);
		reset_buffer(&env_name);
		if (input == '$')
			return (0);
		push_buffer(envexp->buf, input);
		if (input == '\"')
			return (set_state((int *)&envexp->state, E_DOUBLE_QUOTE));
		if (input == '\'')
			return (set_state((int *)&envexp->state, E_SINGLE_QUOTE));
		return (set_state((int *)&envexp->state, E_CHARS));
	}
	return (0);
}
