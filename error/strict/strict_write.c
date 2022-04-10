/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strict_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:47:13 by mypark            #+#    #+#             */
/*   Updated: 2022/04/10 21:11:40 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <errno.h>

int	strict_write(int fd, char *buf, int len)
{
	int	ret;

	ret = write(fd, buf, len);
	if (ret != len)
	{
		if (ret >= 0)
			ret += strict_write(fd, buf, len - ret);
		else if (errno == EINTR)
			ret = strict_write(fd, buf, len);
	}
	return (ret);
}
