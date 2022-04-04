/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 01:05:01 by mypark            #+#    #+#             */
/*   Updated: 2022/04/04 22:08:33 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe_tree.h"
#include "libft.h"
#include "strict.h"
#include <stdlib.h>

t_exe_info	*new_exe_info(char **envp)
{
	t_exe_info	*info;

	info = strict_malloc(sizeof(t_exe_info), 1);
	info->pids = 0;
	info->pipes = 0;
	info->exits = 0;
	info->envp = ft_splitdup(envp);
	info->last_exit = 0;
	return (info);
}

void	del_pid_pipe(void *content)
{
	int	*ptr;

	ptr = (int *)content;
	free(ptr);
}

void	free_exe_info(t_exe_info *info)
{
	if (info->pids)
		ft_lstclear(&info->pids, del_pid_pipe);
	if (info->pipes)
		ft_lstclear(&info->pipes, del_pid_pipe);
	free(info);
}
