/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listen_heredoc_quoted.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 20:18:42 by mypark            #+#    #+#             */
/*   Updated: 2022/04/07 00:49:58 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <readline/readline.h>
#include <signal.h>
#include "utils.h"
#include "libft.h"
#include "error.h"
#include "strict.h"

void	listen_heredoc_quoted(char *limiter, int to)
{
	char	*input;

	signal(SIGINT, ctrl_c_heredoc);
	while (1)
	{
		input = readline("> ");
		if (input == 0 || is_same(input, limiter))
		{
			free(input);
			break;
		}
		ft_putstr_fd(input, to);
		write(to, "\n", 1);
		free(input);
	}
	strict_close(to);
}

