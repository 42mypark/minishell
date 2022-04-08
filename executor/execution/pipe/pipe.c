/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:31:36 by mypark            #+#    #+#             */
/*   Updated: 2022/04/08 18:50:06 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe_tree.h"
#include "strict.h"
#include "pipe.h"

int	*generate_pipe()
{
	int	*pipefd;

	pipefd = strict_malloc(sizeof(int), 2);
	strict_pipe(pipefd);
	return (pipefd);
}

void	set_pipe(int **pipefd, enum e_pipe_position pos, t_exe_info *info)
{
	if (pos == PIPE_LAST)
		info->pipefd_unused = -1;
	else
	{
		(*pipefd) = generate_pipe();
		info->pipefd_unused = (*pipefd)[0];
	}
}