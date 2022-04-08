/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:07:41 by mypark            #+#    #+#             */
/*   Updated: 2022/04/09 04:11:43 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "error.h"
#include "exe_tree.h"
#include "executor.h"
#include "strict.h"
#include "error.h"
#include "constant.h"
#include <string.h>
#include "test.h"


int	builtin_env(t_exetree_node *exnode, t_exe_info *info)
{
	char **envp;

	if (exnode->cmd->args[1])
	{
		print_strerror("env", exnode->cmd->args[1], ERRMSG_ENV_NOFILE);
		return (127);
	}
	envp = info->envp;
	while (*envp)
	{
		ft_putstr_fd(*envp, 1);
		write(1, "\n", 1);
		envp++;
	}
	return (0);
}
