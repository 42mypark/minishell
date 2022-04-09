/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:07:41 by mypark            #+#    #+#             */
/*   Updated: 2022/04/09 19:21:17 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "error.h"
#include "exe_tree.h"
#include "executor.h"
#include "strict.h"
#include <errno.h>
#include <string.h>
#include "test.h"

int	is_opt(char *arg)
{
	int	ai;

	if (arg == NULL)
		return (1);
	if (arg[0] != '-' && arg[1] != 'n')
		return (0);
	ai = 2;
	while (arg[ai])
	{
		if (arg[ai] != 'n')
			return (0);
		ai++;
	}
	return (1);
}

int	builtin_echo(t_exetree_node *exe_node)
{
	char	**args;
	int		opt;
	int		wc;
	int		ai;

	//write error ?
	
	args = exe_node->cmd->args;
	opt = is_opt(args[1]);
	if (!opt)
		write(1, args[1], ft_strlen(args[1]));
	wc = ft_wordcount(args);
	ai = 2;
	while (ai < wc)
	{
		if (ai != wc && !opt)
			write(1, " ", 1);
		write(1, args[ai], ft_strlen(args[ai]));
		ai++;
	}
	if (!opt)
		write(1, "\n", 1);
	return (0);
}
