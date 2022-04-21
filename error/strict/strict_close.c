/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strict_close.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:47:13 by mypark            #+#    #+#             */
/*   Updated: 2022/04/22 08:29:38 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "error.h"
#include "libft.h"

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
