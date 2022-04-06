/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 21:16:13 by mypark            #+#    #+#             */
/*   Updated: 2022/04/06 17:29:41 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe_tree.h"
#include "libft.h"
#include "strict.h"

void	check_close_pipe(int pipe_num, t_exe_info *info)
{
	int		*p;
	t_list	*curr;
	
	curr = info->pipes;
	while (curr)
	{
		p = (int *)curr->content;
		if (p[0] == pipe_num)
		{
			p[0] = -1;
			break;
		}
		if (p[1] == pipe_num)
		{
			p[1] = -1;
			break;
		}
		curr = curr->next;
	}
}

void	close_fd(t_exetree_node *exe_node, t_exe_info *info)
{
	if (exe_node->fd[0] != 0)
	{
		check_close_pipe(exe_node->fd[0], info);
		strict_close(exe_node->fd[0]);
	}
	if (exe_node->fd[1] != 1)
	{
		check_close_pipe(exe_node->fd[1], info);			
		strict_close(exe_node->fd[1]);
	}
}