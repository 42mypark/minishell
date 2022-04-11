/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tokenizer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 01:47:37 by mypark            #+#    #+#             */
/*   Updated: 2022/03/27 14:10:12 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "tokenizer.h"
#include <readline/readline.h>

int	main(void)
{
	t_tokens	*tks;
	char		*input;

	while (1)
	{
		tks = new_tokens();
		input = readline("msh ^ㅁ^/ $$ ");
		tokenizer(tks, input);
		print_tokens(tks);
		free_tokens(tks);
		free(input);
	}
}
