/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:07:41 by mypark            #+#    #+#             */
/*   Updated: 2022/04/09 04:18:40 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "error.h"
#include <errno.h>
#include <string.h>
#include "test.h"
#include "executor.h"
#include "constant.h"

int	builtin_pwd()
{
	char	*dir_name;

	dir_name = getcwd(NULL, 0);
	if (dir_name == 0)
	{
		print_strerror("pwd", dir_name, ERRMSG_GETCWD);
		return (1);
	}
	ft_putstr_fd(dir_name, 1);
	ft_putstr_fd("\n", 1);
	free(dir_name);
	return (0);
}
