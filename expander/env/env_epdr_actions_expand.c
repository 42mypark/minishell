/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_epdr_actions_expand.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 02:59:21 by mypark            #+#    #+#             */
/*   Updated: 2022/03/27 13:52:26 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_expander_utils.h"
#include "token.h"
#include "utils.h"
#include "test.h"

t_env_epdr_state	env_epdr_dq_expand(t_tokens *tks, t_buffer *buf, \
									char input, char **envp)
{
	static t_buffer	env_name;
	char			*env;
	int				i;
	int				start;

	tks++;
	expand_buffer(&env_name);
	if (input == '_' || ft_isalnum(input))
		push_buffer(&env_name, input);
	else
	{
		env = dupenv(env_name.space, envp);
		i = 0;
		start = buf->len;
		while (env[i])
			push_buffer(buf, env[i++]);
		ep_rec_add_back(&buf->ep_rec, new_ep_range(start, buf->len));
		free(env);
		reset_buffer(&env_name);
		if (input == '$')
			return (E_DQ_EXPAND);
		push_buffer(buf, input);
		if (input == '\"')
			return (E_CHARS);
		return (E_DOUBLE_QUOTE);
	}
	return (E_DQ_EXPAND);
}

static int	pass_blank(char *str, int i)
{
	i++;
	while(str[i])
	{
		if (!is_blank(str[i]))
			break;
		i++;
	}
	return (i);
}

static void	env_to_token(t_tokens *tks, t_buffer *buf, char *env)
{
	int		i;
	int		start;

	i = 0;
	if (is_blank(env[0]))
		i = pass_blank(env, i);
	start = buf->len;
	while (env[i])
	{
		if (is_blank(env[i]))
		{
			ep_rec_add_back(&buf->ep_rec, new_ep_range(start, buf->len));
			issue_token(tks, buf);
			start = 0;
			i = pass_blank(env, i);
		}
		else
			push_buffer(buf, env[i++]);
	}
}

t_env_epdr_state	env_epdr_expand(t_tokens *tks, t_buffer *buf, \
									char input, char **envp)
{
	static t_buffer	env_name;
	char			*env;

	expand_buffer(&env_name);
	if (input == '_' || ft_isalnum(input))
		push_buffer(&env_name, input);
	else
	{
		env = dupenv(env_name.space, envp);
		env_to_token(tks, buf, env);
		free(env);
		reset_buffer(&env_name);
		if (input == '$')
			return (E_EXPAND);
		push_buffer(buf, input);
		if (input == '\"')
			return (E_DOUBLE_QUOTE);
		if (input == '\'')
			return (E_SINGLE_QUOTE);
		return (E_CHARS);
	}
	return (E_EXPAND);
}
