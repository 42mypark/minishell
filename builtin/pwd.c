/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:07:41 by mypark            #+#    #+#             */
/*   Updated: 2022/04/09 19:25:35 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constant.h"
#include "error.h"
#include "executor.h"
#include <errno.h>
#include <string.h>
#include <unistd.h>

int	builtin_pwd(void)
{
	char	*dir_name;

	dir_name = getcwd(NULL, 0);
	if (dir_name == 0)
	{
		print_strerror("pwd", dir_name, strerror(errno));
		return (1);
	}
	ft_putstr_fd(dir_name, 1);
	ft_putstr_fd("\n", 1);
	free(dir_name);
	return (0);
}
