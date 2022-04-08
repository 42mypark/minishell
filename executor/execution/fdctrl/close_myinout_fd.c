/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_myinout_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 21:16:13 by mypark            #+#    #+#             */
/*   Updated: 2022/04/08 16:46:28 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe_tree.h"
#include "strict.h"

void	close_myinout_fd(t_exetree_node *exnode)
{
	t_exetree_node	*parent;
	int				is_root_redir;
	int				is_not_parent_fd;
	int				i;

	parent = exnode->parent;
	i = 0;
	while (i < 2)
	{
		is_root_redir = parent == NULL && exnode->fd[i] != i;
		is_not_parent_fd = parent && parent->fd[i] != exnode->fd[i];
		if (is_root_redir)
			strict_close(exnode->fd[i]);
		if (is_not_parent_fd)
			strict_close(exnode->fd[i]);
	}
}
