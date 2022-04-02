/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 01:05:01 by mypark            #+#    #+#             */
/*   Updated: 2022/04/01 15:03:45 by mypark           ###   ########.fr       */
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
	info->envp = envp;
	return (info);
}

void	del_pid_pipe(void *content)
{
	int	*ptr;

	ptr = (int *)content;
	free(ptr);
}

void	insert_new_pipe(t_exe_info *info, int *pipe)
{
	int	*dup;

	dup = strict_malloc(sizeof(int), 2);
	dup[0] = pipe[0];
	dup[1] = pipe[1];
	ft_lstadd_back(&info->pipes, ft_lstnew(dup));
}

void	insert_new_pid(t_exe_info *info, int pid)
{
	int	*dup;

	dup = strict_malloc(sizeof(int), 1);
	dup[0] = pid;
	ft_lstadd_back(&info->pids, ft_lstnew(dup));
}

void	free_exe_info(t_exe_info *info)
{
	ft_lstclear(&info->pids, del_pid_pipe);
	ft_lstclear(&info->pipes, del_pid_pipe);
	free(info);
}
