/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listen_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 20:18:42 by mypark            #+#    #+#             */
/*   Updated: 2022/04/04 15:13:08 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <readline/readline.h>
#include "utils.h"
#include "libft.h"
#include "expander.h"
#include "error.h"
#include "test.h"
#include "strict.h"

static void	write_expanded(int to, char *str, char **envp)
{
	t_tokens	*tks;
	char		**expanded;
	int			i;

	tks = new_tokens();
	env_expander(tks, str, envp);
	expanded = tokens_to_splited(tks);
	i = 0;
	while (expanded[i])
	{
		write(to, expanded[i], ft_strlen(expanded[i]));
		i++;
	}
	ft_splitfree(expanded);
	free_tokens(tks);
}

void	listen_heredoc(char *limiter, int to, char **envp)
{
	char	*input;
	int		dollar;
	char	*back;

	while (1)
	{
		input = readline("> ");
		if (input == 0 || is_same(input, limiter))
		{
			free(input);
			break;
		}
		dollar = ft_strchri(input, '$');
		if (dollar == -1)
			write(to, input, ft_strlen(input));
		else
		{
			back = ft_strdiv(&input, dollar);
			if (back == NULL)
				print_malloc_error();
			write(to, input, dollar);
			write_expanded(to, back, envp);
			free(back);
		}
		write(to, "\n", 1);
		free(input);
	}
	strict_close(to);
}
