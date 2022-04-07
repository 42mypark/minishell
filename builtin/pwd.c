/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:07:41 by mypark            #+#    #+#             */
/*   Updated: 2022/04/08 02:15:59 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "error.h"
#include <errno.h>
#include <string.h>
#include "test.h"
#include "executor.h"

int	builtin_pwd()
{
	char	*dir_name;

	dir_name = getcwd(NULL, 0);
	if (dir_name == 0)
	{
		print_strerror("getcwd", "cannot get working directory.");
		return (1);
	}
	ft_putstr_fd(dir_name, 1);
	ft_putstr_fd("\n", 1);
	return (0);
}
