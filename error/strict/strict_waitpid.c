/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strict_waitpid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:47:13 by mypark            #+#    #+#             */
/*   Updated: 2022/04/04 00:50:03 by mypark           ###   ########.fr       */
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
	char	*msg;

	ret = waitpid(pid, ws, opt);
	if (ret == -1)
	{
		msg = ft_itoa(pid);
		msg = ft_strprepend("wating process of pid ", msg);
		msg = ft_strappend(msg, "fails");
		print_strerror("wait", msg);
	}
	return (ret);
}
