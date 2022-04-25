/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interrupt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:40:39 by mypark            #+#    #+#             */
/*   Updated: 2022/04/22 07:55:32 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "strict.h"

void	ctrl_c(int sig)
{
	(void)sig;
	strict_write(1, "\n", 1);
	rl_replace_line("", 1);
	rl_on_new_line();
	rl_redisplay();
}

void	ctrl_c2(int sig)
{
	(void)sig;
	strict_write(1, "\n", 1);
	rl_replace_line("", 1);
	rl_on_new_line();
}

void	ctrl_c_heredoc(int sig)
{
	(void)sig;
	exit(1);
}

void	ctrl_quit(int sig)
{
	(void)sig;
	strict_write(1, "Quit: 3\n", 8);
}
