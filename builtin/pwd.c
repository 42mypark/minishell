/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:07:41 by mypark            #+#    #+#             */
/*   Updated: 2022/04/06 17:04:55 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "error.h"
#include <errno.h>
#include <string.h>
#include "test.h"
#include "executor.h"

int	builtin_pwd(t_exetree_node *exe_node)
{
	char	*dir_name;
	
	dir_name = getcwd(NULL, 0);
	if (dir_name == 0)
	{
		print_strerror("getcwd", "cannot get working directory.");
		restore_inout_fd(exe_node);
		return (1);
	}
	ft_putstr_fd(dir_name, 1);
	ft_putstr_fd("\n", 1);
	restore_inout_fd(exe_node);
	return (0);
}