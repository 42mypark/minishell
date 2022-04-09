/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strict_dup2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:47:13 by mypark            #+#    #+#             */
/*   Updated: 2022/04/09 15:56:26 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>
#include "error.h"
#include "test.h"

void	strict_dup2(int srcfd, int dstfd)
{
	int		ret;
	char	*srcfd_str;
	char	*dstfd_str;

	ret = dup2(srcfd, dstfd);
	if (ret == -1)
	{
		srcfd_str = ft_strprepend("source: ", ft_itoa(srcfd));
		srcfd_str = ft_strappend(srcfd_str, " ");
		dstfd_str = ft_strprepend("destination: ", ft_itoa(dstfd));
		dstfd_str = ft_strmerge(srcfd_str, dstfd_str);
		print_strerror("dup2", dstfd_str, strerror(errno));
		free(dstfd_str);
	}
}
