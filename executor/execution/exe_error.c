/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 23:46:16 by mypark            #+#    #+#             */
/*   Updated: 2022/04/10 18:17:49 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe_tree.h"
#include "info.h"
#include "fdctrl.h"
#include "error.h"
#include <unistd.h>
#include <stdlib.h>

int	exe_error(t_exetree_node *exnode, t_exe_info *info)
{
	close_unused_pipe(exnode, info);
	close_myinout_fd(exnode);
	print_strerror("file", NULL, (char *)exnode->err->msg);
	if (exnode->parent && exnode->parent->type == EXE_PIPE)
		exit(exnode->err->exit_status);
	return (exnode->err->exit_status);
}
