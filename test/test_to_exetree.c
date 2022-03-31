/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_to_exetree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:23:28 by mypark            #+#    #+#             */
/*   Updated: 2022/04/01 03:08:42 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include <readline/readline.h>
#include <sys/wait.h>

void	testleak(void)
{
	system("valgrind ./minishell --leak-check=full");
}

int	main(int argc, char **argv, char **envp)
{
	t_tokens			*tks;
	t_parsetree_node	*pt_head;
	t_exetree_node		*exe_head;
	char				*input;
	int					pcnt;
	int					ecnt;
	pid_t				pid;
	int					exit_status;
	char				*a;
	t_exe_info			*info;

	atexit(testleak);
	info = new_exe_info(envp);

	argc++;
	a = argv[0];
	a++;
	while (1)
	{
		pcnt = 0;
		ecnt = 0;
		input = readline("msh ^ㅁ^/ $$ ");
		if (input[0] == '\0')
		{
			free(input);
			continue;
		}
		tks = new_tokens();
		pid = fork();
		if (pid == 0)
		{
			tokenizer(tks, input);
			print_tokens(tks);
			syntax_error_check(tks);
			pt_head = parse_script(tks);
			expand_tour_tree(pt_head, envp);
			printf("\n***** parse tree *****\n");
			print_parsetree(pt_head, &pcnt);
			exe_head = make_exetree(pt_head, info);
			free_parsetree(pt_head);
			printf("\n***** exe tree *****\n");
			print_exetree(exe_head, &ecnt);
			print_exe_info(info);
			free_exe_info(info);
			free(input);
			exit(0);
		}
		else
			waitpid(pid, &exit_status, 0);
		free_tokens(tks);
	}
}
