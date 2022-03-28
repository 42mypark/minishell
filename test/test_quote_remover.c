/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_quote_remover.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:23:28 by mypark            #+#    #+#             */
/*   Updated: 2022/03/29 02:24:17 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include <readline/readline.h>
#include <sys/wait.h>

int	main(int argc, char **argv, char **envp)
{
	t_tokens			*tks;
	t_parsetree_node	*pt_head;
	char				*input;
	int					cnt;
	pid_t				pid;
	int					exit_status;
	char				*a;

	argc++;
	a = argv[0];
	a++;
	while (1)
	{
		cnt = 0;
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
			print_parsetree(pt_head, &cnt); // 0
			expand_env(pt_head, envp);
			print_parsetree(pt_head, &cnt); // 1
			expand_wildcard(pt_head, envp);
			print_parsetree(pt_head, &cnt); // 2
			remove_quote(pt_head, envp);
			print_parsetree(pt_head, &cnt); // 3
			//free_parsetree(pt_head);
		}
		else
			waitpid(pid, &exit_status, 0);
		free_tokens(tks);
		free(input);
	}
}
