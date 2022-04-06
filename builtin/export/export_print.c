/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:07:41 by mypark            #+#    #+#             */
/*   Updated: 2022/04/07 03:36:18 by mypark           ###   ########.fr       */
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

static int	is_all_checked(char *check, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (check[i] == 0)
			return (0);
		i++;
	}
	return (1);
}

static char	*get_ordered_var(char **envp, char *check)
{
	int	fast;
	int	i;

	i = -1;
	fast = -1;
	while (envp[++i])
	{
		if (fast == -1 && check[i] == 0)
			fast = i++;
		if (fast == -1)
			continue;
		if (ft_strncmp(envp[i], "_", 1) == 0)
			check[i] = 1;
		if (check[i] == 0 && ft_strncmp(envp[i], envp[fast], -1) < 0)
			fast = i;
	}
	check[fast] = 1;
	return (envp[fast]);
}

void	export_print(char **envp)
{
	int		i;
	int		eq;
	int		wc;
	char	*check;
	char	*var;

	wc = ft_wordcount(envp);
	check = strict_malloc(sizeof(char), wc);
	i = 0;
	while (i < wc)
		check[i++] = 0;
	while (!is_all_checked(check, wc))
	{
		var = get_ordered_var(envp, check);
		eq = ft_strchri(var, '=');
		ft_putstr_fd("declare -x ", 1);
		write(1, var, eq + 1);
		write(1, "\"", 1);
		if (var[eq + 1])
			ft_putstr_fd(var + eq + 1, 1);
		write(1, "\"\n", 2);
	}
	free(check);
}
