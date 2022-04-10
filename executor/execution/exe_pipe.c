/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 23:46:16 by mypark            #+#    #+#             */
/*   Updated: 2022/04/10 18:16:59 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe_tree.h"
#include "info.h"
#include "execution.h"
#include "fdctrl.h"
#include "strict.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "pipe.h"
#include "test.h"

static void	exe_pipe_child(\
	t_exetree_node *exchild, \
	int infd, int outfd, \
	t_exe_info *info\
)
{
	pid_t	pid;
	int		fd[2];

	fd[0] = infd;
	fd[1] = outfd;
	pid = strict_fork();
	if (pid == 0)
		exit(execute_node(exchild, fd, info));
	else
	{
		receive_parent_fd(exchild, fd);
		close_myinout_fd(exchild);
		insert_new_pid(info, pid);
	}
}

static void	wait_childs(t_exe_info *info)
{
	t_list	*pids;
	t_list	*poped;
	int		pid;
	int		ws;

	pids = info->pids;
	while (pids)
	{
		poped = ft_lstpop_front(&pids);
		pid = ((int *)poped->content)[0];
		waitpid(pid, &ws, 0);
		insert_new_exit(info, calc_exit_status(ws));
		ft_lstdelone(poped, free);
	}
	info->pids = NULL;
}

int	exe_pipe(t_exetree_node *exnode, int *parent_fd, t_exe_info *info)
{
	t_pipelines	*pl_curr;
	int			*pipe_prev;
	int			*pipe_curr;
	int			*exit_status;

	receive_parent_fd(exnode, parent_fd);
	pl_curr = exnode->pipelines;
	set_pipe(&pipe_prev, PIPE_NOT_LAST, info);
	exe_pipe_child(pl_curr->content, exnode->fd[0], pipe_prev[1], info);
	pl_curr = pl_curr->next;
	while (pl_curr->next)
	{
		set_pipe(&pipe_curr, PIPE_NOT_LAST, info);
		exe_pipe_child(pl_curr->content, pipe_prev[0], pipe_curr[1], info);
		free(pipe_prev);
		pipe_prev = pipe_curr;
		pl_curr = pl_curr->next;
	}
	set_pipe(&pipe_curr, PIPE_LAST, info);
	exe_pipe_child(pl_curr->content, pipe_prev[0], exnode->fd[1], info);
	free(pipe_prev);
	wait_childs(info);
	close_myinout_fd(exnode);
	exit_status = ft_lstlast(info->exits)->content;
	return (*exit_status);
}
