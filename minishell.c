/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:23:28 by mypark            #+#    #+#             */
/*   Updated: 2022/04/09 04:05:59 by mypark           ###   ########.fr       */
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

	argc++;
	argv++;
	info = new_exe_info(envp);
	strict_dup2(0, 3);
	strict_dup2(1, 4);
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
