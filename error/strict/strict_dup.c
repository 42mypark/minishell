/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strict_dup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:47:13 by mypark            #+#    #+#             */
/*   Updated: 2022/04/22 08:29:54 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>
#include "error.h"
#include "libft.h"

int	strict_dup(int fd)
{
	int		ret;
	char	*fd_str;

	ret = dup(fd);
	if (ret == -1)
	{
		fd_str = ft_itoa(fd);
		print_strerror("dup2", fd_str, strerror(errno));
		free(fd_str);
	}
	return (ret);
}
