/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_signal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 17:05:23 by mypark            #+#    #+#             */
/*   Updated: 2022/04/09 19:30:51 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>

#define PROMPT "hello: "

// rl_on_new_line
// rl_replace_line
// readline
// rl_redisplay

void	ctrl_escape()
{
	rl_replace_line("", 0);
}

void	ctrl_c(int sig)
{
	(void)sig;
	printf("\n");
	rl_replace_line("", 1);
	rl_on_new_line();
	rl_redisplay();
}

int	main()
{
	char	*input;

	signal(3, SIG_IGN);
	signal(2, ctrl_c);
	rl_on_new_line();
	while (1)
	{
		printf("before readline\n");
		input = readline(PROMPT);
		if (input && *input)
			add_history(input);
		if (input == NULL)
		{
			printf("\nlog out\n");
			exit(0);
		}
		printf("%p\n", input);
	}
}
