/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:07:41 by mypark            #+#    #+#             */
/*   Updated: 2022/04/09 19:28:22 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constant.h"
#include "error.h"
#include "info.h"
#include "exe_tree.h"
#include <string.h>
#include <unistd.h>

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
