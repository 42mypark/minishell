/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_bool_child.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 23:46:16 by mypark            #+#    #+#             */
/*   Updated: 2022/04/04 01:28:28 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe_tree.h"
#include "info.h"
#include "executor.h"
#include "strict.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "test.h"

int	exe_bool_child(t_exetree_node *child, int infd, int outfd, t_exe_info *info)
{
	pid_t	pid;
	int		ws;

	pid = strict_fork();
	if (pid)
	{
		strict_waitpid(pid, &ws, 0);
		return (calc_exit_status(ws));
	}
	else
	{
		execute_node(child, infd, outfd, info);
		//exit(0);
	}
	return (1);
}
