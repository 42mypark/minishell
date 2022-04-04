/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_executor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:23:28 by mypark            #+#    #+#             */
/*   Updated: 2022/04/04 19:31:14 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>
#include <sys/wait.h>

void	testleak(void)
{
	system("leaks minishell");
}

void	ctrl_c()
{
	printf("\n");
	rl_replace_line("", 1);
	rl_on_new_line();
	rl_redisplay();
}

int	main(int argc, char **argv, char **envp)
{
	t_tokens			*tks;
	t_parsetree_node	*pt_head;
	t_exetree_node		*exe_head;
	char				*input;
	//int					pcnt;
	int					ecnt;
	pid_t				pid;
	int					exit_status;
	char				*a;
	t_exe_info			*info;

	//atexit(testleak);
	info = new_exe_info(envp);
	argc++;
	a = argv[0];
	a++;
	signal(3, SIG_IGN);
	while (1)
	{
		signal(2, ctrl_c);
		//pcnt = 0;
		ecnt = 0;
		input = readline("msh ^ㅁ^/ $$ ");
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
			continue;
		}
		tks = new_tokens();
		pid = fork();
		if (pid == 0)
		{
			signal(2, SIG_IGN);
			tokenizer(tks, input);
			free(input);
			printf("\n***** tokens *****\n");
			//print_tokens(tks);
			syntax_error_check(tks);
			pt_head = parser(tks);
			expander(pt_head, envp);
			printf("\n***** parse tree *****\n");
			//print_parsetree(pt_head, &pcnt);
			exe_head = make_exetree(pt_head, info);
			free_parsetree(pt_head);
			printf("\n***** exe tree *****\n");
			print_exetree(exe_head, &ecnt);
			print_exe_info(info);
			printf("\n***** cmd result *****\n");
			executor(exe_head, info);
			exit(0);
		}
		else
		{
			signal(2, SIG_IGN);
			waitpid(pid, &exit_status, 0);
			printf("%d\n", calc_exit_status(exit_status));
		}
		free(input);
		free_tokens(tks);
	}
}
