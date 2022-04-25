/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 00:12:54 by mypark            #+#    #+#             */
/*   Updated: 2022/04/22 08:27:27 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strict.h"
#include "heredoc.h"
#include "interrupt.h"
#include <sys/wait.h>
#include <stdlib.h>

void	make_heredoc(t_exetree_node *e_nd, t_token *tk, t_exe_info *info)
{
	int		p[2];
	pid_t	pid;
	int		ws;

	if (e_nd->fd[0] != 0)
		strict_close(e_nd->fd[0]);
	strict_pipe(p);
	pid = strict_fork();
	if (pid)
	{
		strict_waitpid(pid, &ws, 0);
		info->heredoc_fail = calc_exit_status(ws);
		strict_close(p[1]);
		e_nd->fd[0] = p[0];
	}
	else
	{
		if (tk->type == TK_QUOTED_STR)
			listen_heredoc_quoted(tk->content, p[1]);
		else
			listen_heredoc(tk->content, p[1], info);
		exit(0);
	}
}
