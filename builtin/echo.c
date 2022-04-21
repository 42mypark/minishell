/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:07:41 by mypark            #+#    #+#             */
/*   Updated: 2022/04/22 07:19:17 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "error.h"
#include "exe_tree.h"
#include "executor.h"
#include "strict.h"
#include "constant.h"
#include <errno.h>
#include <string.h>

int	is_opt(char *arg)
{
	int	ai;

	if (arg[1] == '\0')
		return (0);
	if (arg[0] != '-' || arg[1] != 'n')
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

	args = exe_node->cmd->args;
	opt = 0;
	ai = 0;
	while (args[++ai] && is_opt(args[ai]))
		opt = 1;
	wc = ft_wordcount(args);
	while (ai < wc)
	{
		strict_write(1, args[ai], ft_strlen(args[ai]));
		if (ai != wc - 1)
			strict_write(1, " ", 1);
		ai++;
	}
	if (!opt || args[1] == FT_NULL || args[1][0] == '\0')
		strict_write(1, "\n", 1);
	return (0);
}
