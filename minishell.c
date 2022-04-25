/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:23:28 by mypark            #+#    #+#             */
/*   Updated: 2022/04/22 07:52:17 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constant.h"
#include "exe_tree.h"
#include "executor.h"
#include "interrupt.h"
#include "parser.h"
#include "strict.h"
#include <stdio.h>
#include <readline/history.h>
#include <readline/readline.h>
#include <signal.h>
#include <sys/wait.h>
#include <termios.h>

static int	is_all_blank(char *input)
{
	while (*input)
	{
		if (*input != ' ')
			return (0);
		input++;
	}
	return (1);
}

static char	*ft_readline(char *prompt)
{
	char			*input;
	struct termios	termios;

	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, ctrl_c);
	tcgetattr(STDIN_FILENO, &termios);
	termios.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, &termios);
	input = readline(prompt);
	if (input && *input)
		add_history(input);
	if (input == 0)
	{
		strict_putstr_fd(" exit\n", 2);
		exit(0);
	}
	if (input[0] == '\0' || is_all_blank(input))
	{
		free(input);
		return (FT_NULL);
	}
	signal(SIGINT, SIG_IGN);
	termios.c_lflag |= ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &termios);
	return (input);
}

int	main(int argc, char **argv, char **envp)
{
	t_parsetree_node	*parse_tree;
	t_exe_info			*info;
	char				*input;

	(void)argc;
	(void)argv;
	info = new_exe_info(envp);
	info->std_in = strict_dup(0);
	info->std_out = strict_dup(1);
	while (1)
	{
		input = ft_readline("msh ^ㅁ^/ $$ ");
		if (input == FT_NULL)
			continue ;
		parse_tree = parser(input, info);
		if (parse_tree == FT_NULL)
			continue ;
		executor(parse_tree, info);
	}
}
