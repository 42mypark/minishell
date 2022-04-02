/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:51:01 by mypark            #+#    #+#             */
/*   Updated: 2022/04/01 15:02:36 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info.h"
#include "libft.h"
#include "strict.h"
#include <stdlib.h>

t_cmd_info	*new_cmd_info(char *cmd, char **args, char **envp)
{
	t_cmd_info *info;

	info = strict_malloc(sizeof(t_cmd_info), 1);
	info->cmd = cmd;
	info->args = args;
	info->envp = envp;
	return (info);
}

void	free_cmd_info(t_cmd_info *info)
{
	free(info->cmd);
	ft_free_splited(info->args);
	free(info);
}