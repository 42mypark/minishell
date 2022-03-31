/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strict_dup2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:47:13 by mypark            #+#    #+#             */
/*   Updated: 2022/04/01 02:12:35 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>
#include "error.h"

void	strict_dup2(int srcfd, int dstfd)
{
	int	ret;

	ret = dup2(srcfd, dstfd);
	if (ret == -1)
		print_strerror(strerror(errno));
}
