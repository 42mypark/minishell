/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:23:28 by mypark            #+#    #+#             */
/*   Updated: 2022/04/10 21:09:43 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>
#include <sys/wait.h>
#include "strict.h"

char	*ft_readline(char *prompt)
{
	char	*input;

	input = readline(prompt);
	if (input && *input)
		add_history(input);
	if (input == 0)
	{
		printf(" exit\n");
		exit(0);
	}
	if (input[0] == '\0')
	{
		free(input);
		return (NULL);
	}
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
	signal(SIGQUIT, SIG_IGN);
	while (1)
	{
		signal(SIGINT, ctrl_c);
		input = ft_readline("msh ^ㅁ^/ $$ ");
		if (input == NULL)
			continue ;
		signal(SIGINT, SIG_IGN);
		parse_tree = parser(input, info);
		if (parse_tree == NULL)
			continue ;
		executor(parse_tree, info);
	}
}
