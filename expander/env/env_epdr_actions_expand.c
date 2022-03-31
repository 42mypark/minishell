/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_epdr_actions_expand.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 02:59:21 by mypark            #+#    #+#             */
/*   Updated: 2022/03/31 18:46:46 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_expander_utils.h"
#include "token.h"
#include "utils.h"
#include "test.h"

static void	push_env_to_buffer(t_buffer *env_name, t_buffer *buf, char **envp)
{
	char	*env;
	int		i;
	int		start;

	env = dupenv(env_name->space, envp);
	i = 0;
	start = buf->len;
	while (env[i])
		push_buffer(buf, env[i++]);
	ep_rec_add_back(&buf->ep_rec, new_ep_range(start, buf->len));
	free(env);
}

t_env_epdr_state	env_epdr_dq_expand(t_tokens *tks, t_buffer *buf, \
									char input, char **envp)
{
	static t_buffer	env_name;

	tks++;
	if (input == '_' || ft_isalnum(input))
		push_buffer(&env_name, input);
	else
	{
		push_env_to_buffer(&env_name, buf, envp);
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
	int		i;

	i = 0;
	if (is_blank(env[0]))
		i = pass_blank(env, i);
	buf->start = buf->len;
	while (env[i])
	{
		if (is_blank(env[i]))
		{
			ep_rec_add_back(&buf->ep_rec, new_ep_range(buf->start, buf->len));
			issue_token(tks, buf);
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
