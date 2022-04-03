/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strict_execve.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:47:13 by mypark            #+#    #+#             */
/*   Updated: 2022/04/03 16:27:31 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>
#include "error.h"

void	strict_execve(char *cmd, char **args, char **envp)
{
	int	ret;
	ret = execve(cmd, args, envp);
	if (ret == -1)
		print_strerror("execve", strerror(errno));
}
