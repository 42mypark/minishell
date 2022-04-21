/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listen_heredoc_quoted.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 20:18:42 by mypark            #+#    #+#             */
/*   Updated: 2022/04/22 07:53:36 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "interrupt.h"
#include "libft.h"
#include "strict.h"
#include "utils.h"
#include <fcntl.h>
#include <stdio.h>
#include <readline/readline.h>
#include <signal.h>
#include <unistd.h>

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
			break ;
		}
		strict_putstr_fd(input, to);
		strict_write(to, "\n", 1);
		free(input);
	}
	strict_close(to);
}
