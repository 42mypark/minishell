/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_to_exetree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:23:28 by mypark            #+#    #+#             */
/*   Updated: 2022/03/30 20:45:31 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include <readline/readline.h>
#include <sys/wait.h>

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

	argc++;
	a = argv[0];
	a++;
	while (1)
	{
		pcnt = 0;
		ecnt = 0;
		tks = new_tokens();
		input = readline("msh ^ㅁ^/ $$ ");
		if (input[0] == '\0')
			continue;
		pid = fork();
		if (pid == 0)
		{
			tokenizer(tks, input);
			print_tokens(tks);
			syntax_error_check(tks);
			pt_head = parse_script(tks);
			expand_env(pt_head, envp);
			expand_wildcard(pt_head, envp);
			remove_quote(pt_head, envp);
			printf("\n***** parse tree *****\n");
			print_parsetree(pt_head, &pcnt);
			exe_head = parse_to_exe(pt_head, 0, 1, envp);
			printf("\n***** exe tree *****\n");
			print_exetree(exe_head, &ecnt);
			exit(0);
		}
		else
			waitpid(pid, &exit_status, 0);
		free_tokens(tks);
		free(input);
	}
}
