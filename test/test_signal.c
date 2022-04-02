/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_signal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 17:05:23 by mypark            #+#    #+#             */
/*   Updated: 2022/04/02 22:47:46 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <signal.h>
#include <readline/readline.h>
#include <stdlib.h>

void	ctrl_escape()
{
	ft_putstr_fd("im control esc\n", 1);
	
}

void	ctrl_c()
{
	write(1, "asdf\n", 5);
	rl_replace_line("hello  : ", 0);
}

int	main()
{
	char	*input;
	
	signal(3, ctrl_escape);
	signal(2, ctrl_c);
	while (1)
	{
		input = readline("hello:");
		rl_on_new_line();
		if (input == NULL)
		{
			printf("\nlog out\n");
			exit(0);
		}
		printf("%s\n", input);
	}
}