/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 23:46:16 by mypark            #+#    #+#             */
/*   Updated: 2022/04/12 03:43:24 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe_tree.h"
#include "info.h"
#include "fdctrl.h"
#include "error.h"
#include "constant.h"
#include <unistd.h>
#include <stdlib.h>

int	exe_error(t_exetree_node *exnode, t_exe_info *info)
{
	close_unused_pipe(exnode, info);
	close_myinout_fd(exnode);
	print_strerror("file", FT_NULL, (char *)exnode->err->msg);
	if (exnode->parent && exnode->parent->type == EXE_PIPE)
		exit(exnode->err->exit_status);
	return (exnode->err->exit_status);
}
