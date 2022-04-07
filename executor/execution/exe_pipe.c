/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 23:46:16 by mypark            #+#    #+#             */
/*   Updated: 2022/04/08 06:00:14 by mypark           ###   ########.fr       */
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

static void	exe_pipe_child(t_exetree_node *exnode, int infd, int outfd, t_exe_info *info)
{
	pid_t	pid;
	int		fd[2];

	fd[0] = infd;
	fd[1] = outfd;
	pid = strict_fork();
	printf("%d\n", pid);
	if(pid)
	{
		inherit_parent_fd(exnode, fd);
		insert_new_pid(info, pid);
		close_inout_fd(exnode);//?
	}
	else
		exit(execute_node(exnode, fd, info));
}

static void	wait_childs(t_exe_info *info)
{
	t_list	*pids;
	t_list	*poped;
	int		pid;
	int		ws;

	pids = info->pids;
	while(pids)
	{
		poped = ft_lstpop_front(&pids);
		pid = ((int *)poped->content)[0];
		waitpid(pid, &ws, 0);
		insert_new_exit(info, calc_exit_status(ws));
		ft_lstdelone(poped, free);
	}
	info->pids = NULL;
}

static int	*generate_pipe()
{
	int	*pipefd;

	pipefd = strict_malloc(sizeof(int), 2);
	strict_pipe(pipefd);
	return (pipefd);
}

int	exe_pipe(t_exetree_node *exnode, int *parent_fd, t_exe_info *info)
{
	t_pipelines	*curr;
	int			*prev_pipe;
	int			*curr_pipe;
	int			*exit_status;

	inherit_parent_fd(exnode, parent_fd);
	curr = exnode->pls;
	prev_pipe = generate_pipe();
	info->pipefd_unused = prev_pipe[0];
	exe_pipe_child(curr->content, exnode->fd[0], prev_pipe[1], info);
	curr = curr->next;
	while (curr->next)
	{
		curr_pipe = generate_pipe();
		info->pipefd_unused = curr_pipe[0];
		exe_pipe_child(curr->content, prev_pipe[0], curr_pipe[1], info);
		free(prev_pipe);
		prev_pipe = curr_pipe;
		curr = curr->next;
	}
	exe_pipe_child(curr->content, prev_pipe[0], exnode->fd[1], info);
	free(prev_pipe);
	wait_childs(info);
	close_inout_fd(exnode);
	exit_status = ft_lstlast(info->exits)->content;
	return (*exit_status);
}
