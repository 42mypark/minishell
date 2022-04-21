/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 23:57:19 by mypark            #+#    #+#             */
/*   Updated: 2022/04/22 07:24:45 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "exe_tree.h"
#include "executor.h"
#include "strict.h"
#include "libft.h"
#include <errno.h>
#include <string.h>
#include <unistd.h>

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
			continue ;
		if (ft_strncmp(envp[i], "_=", 2) == 0)
			check[i] = 1;
		if (check[i] == 0 && ft_strncmp(envp[i], envp[fast], -1) < 0)
			fast = i;
	}
	check[fast] = 1;
	return (envp[fast]);
}

static void	print_var(char *var)
{
	int	eq;

	eq = ft_strchri(var, '=');
	strict_putstr_fd("declare -x ", 1);
	if (eq != -1)
	{
		strict_write(1, var, eq + 1);
		strict_write(1, "\"", 1);
		if (var[eq + 1])
			strict_putstr_fd(var + eq + 1, 1);
		strict_write(1, "\"\n", 2);
	}
	else
	{
		strict_putstr_fd(var, 1);
		strict_write(1, "\n", 1);
	}
}

void	export_print(char **envp)
{
	int		wc;
	char	*check;
	char	*var;

	wc = ft_wordcount(envp);
	check = strict_malloc(sizeof(char), wc);
	ft_memset(check, 0, wc);
	while (!is_all_checked(check, wc))
	{
		var = get_ordered_var(envp, check);
		print_var(var);
	}
	free(check);
}
