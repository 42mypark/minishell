/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:23:28 by mypark            #+#    #+#             */
/*   Updated: 2022/03/22 19:17:42 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "parser.h"
#include "error.h"
#include "tokenizer.h"
#include <readline/readline.h>

int	main(void)
{
	t_tokens			*tks;
	t_parsetree_node	*pt_head;
	char				*input;
	
	while (1)
	{
		tks = new_tokens();
		input = readline("msh ^ㅁ^/ $$ ");
		tokenizer(tks, input);
		print_tokens(tks);
		syntax_error_check(tks);
		// pt_head = parse_script(tks);
		free_tokens(tks);
		free(input);
	}
}