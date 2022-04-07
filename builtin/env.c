/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:07:41 by mypark            #+#    #+#             */
/*   Updated: 2022/04/08 02:17:20 by mypark           ###   ########.fr       */
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

int	builtin_env(t_exe_info *info)
{
	// handle error more than 1 args?
	char **envp;

	envp = info->envp;
	while (*envp)
	{
		ft_putstr_fd(*envp, 1);
		write(1, "\n", 1);
		envp++;
	}
	return (0);
}
