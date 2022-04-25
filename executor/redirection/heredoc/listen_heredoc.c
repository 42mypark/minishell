/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listen_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 20:18:42 by mypark            #+#    #+#             */
/*   Updated: 2022/04/22 07:54:03 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "expander.h"
#include "interrupt.h"
#include "libft.h"
#include "strict.h"
#include "utils.h"
#include <fcntl.h>
#include <stdio.h>
#include <readline/readline.h>
#include <signal.h>
#include <unistd.h>

static void	write_expanded(int to, char *str, t_exe_info *info)
{
	t_tokens	*tks;
	char		**expanded;
	int			i;

	tks = new_tokens();
	env_expander(tks, str, info);
	expanded = tokens_to_splited(tks);
	i = 0;
	while (expanded[i])
	{
		strict_write(to, expanded[i], ft_strlen(expanded[i]));
		i++;
	}
	ft_splitfree(expanded);
	free_tokens(tks);
}

static int	env_end_index(char *str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (!(ft_isalnum(str[i]) || str[i] == '_'))
			return (i);
		i++;
	}
	return (i);
}

void	write_input(char *input, int to, t_exe_info *info)
{
	int		dollar;
	int		env_end;
	char	*env;

	while (*input)
	{
		dollar = ft_strchri(input, '$');
		if (dollar == -1)
		{
			strict_write(to, input, ft_strlen(input));
			break ;
		}
		else
		{
			strict_write(to, input, dollar);
			input += dollar;
			env_end = env_end_index(input);
			env = ft_strndup(input, env_end);
			write_expanded(to, env, info);
			input += env_end;
			free(env);
		}
	}
}

void	listen_heredoc(char *limiter, int to, t_exe_info *info)
{
	char	*input;

	signal(SIGINT, ctrl_c_heredoc);
	while (1)
	{
		input = readline("> ");
		if (input == 0 || is_same(input, limiter))
		{
			free(input);
			break ;
		}
		write_input(input, to, info);
		strict_write(to, "\n", 1);
		free(input);
	}
	strict_close(to);
}
