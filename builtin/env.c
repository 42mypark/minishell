/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:07:41 by mypark            #+#    #+#             */
/*   Updated: 2022/04/12 16:55:20 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constant.h"
#include "error.h"
#include "info.h"
#include "exe_tree.h"
#include "strict.h"
#include <string.h>
#include <unistd.h>

int	builtin_env(t_exetree_node *exnode, t_exe_info *info)
{
	int		i;
	char	**envp;

	if (exnode->cmd->args[1])
	{
		print_strerror("env", exnode->cmd->args[1], ERRMSG_ENV_NOFILE);
		return (127);
	}
	envp = info->envp;
	i = -1;
	while (envp[++i])
	{
		if (ft_strchri(envp[i], '=') == -1)
			continue ;
		strict_putstr_fd(envp[i], 1);
		strict_write(1, "\n", 1);
	}
	return (0);
}
