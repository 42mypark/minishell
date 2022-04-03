/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listen_heredoc_quoted.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 20:18:42 by mypark            #+#    #+#             */
/*   Updated: 2022/04/04 01:52:10 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "utils.h"
#include "libft.h"
#include "error.h"
#include "strict.h"

void	listen_heredoc_quoted(char *limiter, int to)
{
	char	*input;
	char	*back;

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

