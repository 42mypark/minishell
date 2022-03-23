/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_epdr_expand.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 02:59:21 by mypark            #+#    #+#             */
/*   Updated: 2022/03/24 04:03:43 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_expander_utils.h"
#include "token.h"
#include "utils.h"

t_env_epdr_state	env_epdr_dq_expand(t_tokens *tks, t_buffer *buf, \
									char input, char **envp)
{
	static t_buffer	env_name;
	char			*env;

	expand_buffer(&env_name);
	if (ft_isalnum(input))
		push_buffer(&env_name, input);
	else
	{
		env = dupenv(env_name.space, envp);
		while (*env)
			push_buffer(buf, *(env++));
		free(env);
		reset_buffer(&env_name);
		push_buffer(buf, input);
		if (input == '\"')
			return (E_CHARS);
		return (E_DOUBLE_QUOTE);
	}
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

t_env_epdr_state	env_epdr_expand(t_tokens *tks, t_buffer *buf, \
									char input, char **envp)
{
	static t_buffer	env_name;
	char			*env;
	int				i;

	expand_buffer(&env_name);
	if (ft_isalnum(input))
		push_buffer(&env_name, input);
	else
	{
		env = dupenv(env_name.space, envp);
		i = 0;
		while (env[i])
		{
			if (is_blank(env[i]))
			{
				issue_token(tks, buf);
				i = pass_blank(env, i);
			}
			else
				push_buffer(buf, env[i++]);
		}
		free(env);
		reset_buffer(&env_name);
		push_buffer(buf, input);
		if (input == '\"')
			return (E_CHARS);
		return (E_DOUBLE_QUOTE);
	}
}
