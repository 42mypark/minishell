/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strict_waitpid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:47:13 by mypark            #+#    #+#             */
/*   Updated: 2022/04/09 16:01:16 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include "error.h"
#include "libft.h"

int	strict_waitpid(pid_t pid, int *ws, int opt)
{
	int		ret;
	char	*pid_str;

	ret = waitpid(pid, ws, opt);
	if (ret == -1)
	{
		pid_str = ft_itoa(pid);
		print_strerror("wait", pid_str, strerror(errno));
		free(pid_str);
	}
	return (ret);
}
