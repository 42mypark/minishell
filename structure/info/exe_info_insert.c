/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_info_insert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 01:05:01 by mypark            #+#    #+#             */
/*   Updated: 2022/04/04 01:09:34 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "strict.h"
#include "info.h"
#include <stdlib.h>

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

void	insert_new_exit(t_exe_info *info, int exit)
{
	int	*dup;

	dup = strict_malloc(sizeof(int), 1);
	dup[0] = exit;
	ft_lstadd_back(&info->exits, ft_lstnew(dup));
}
