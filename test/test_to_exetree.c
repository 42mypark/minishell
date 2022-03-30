/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_to_exetree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:23:28 by mypark            #+#    #+#             */
/*   Updated: 2022/03/31 02:17:55 by mypark           ###   ########.fr       */
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
	t_exe_info			*info;

	info = new_exe_info(envp);

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
			exe_head = make_exetree(pt_head, info);
			free_parsetree(pt_head);
			printf("\n***** exe tree *****\n");
			print_exetree(exe_head, &ecnt);
			print_exe_info(info);
			free_exe_info(info);
			exit(0);
		}
		else
			waitpid(pid, &exit_status, 0);
		free_tokens(tks);
		free(input);
	}
}
