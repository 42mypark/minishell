/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strict_close.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:47:13 by mypark            #+#    #+#             */
/*   Updated: 2022/04/09 04:18:21 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "error.h"
#include "test.h"

void	strict_close(int fd)
{
	int		ret;
	char	*fd_str;

	ret = close(fd);
	if (ret == -1)
	{
		fd_str = ft_itoa(fd);
		print_strerror("close", fd_str, strerror(errno));
		free(fd_str);
	}
}
