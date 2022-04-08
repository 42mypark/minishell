/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive_parent_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 21:54:48 by mypark            #+#    #+#             */
/*   Updated: 2022/04/05 15:54:27 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe_tree.h"
#include "strict.h"
#include "test.h"

void	receive_parent_fd(t_exetree_node *exnode, int *parent_fd)
{
	int	is_std;
	int	is_pipe;
	int	i;

	i = 0;
	while (i < 2)
	{
		is_std = exnode->fd[i] == i;
		is_pipe = exnode->parent && parent_fd[i] != exnode->parent->fd[i];
		if (is_std)
			exnode->fd[i] = parent_fd[i];
		else if (is_pipe)
			strict_close(parent_fd[i]);
		i++;
	}
	int cnt = 0;
	//print_exetree_node(exnode, &cnt);
}
