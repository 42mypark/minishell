/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strict_dup2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:47:13 by mypark            #+#    #+#             */
/*   Updated: 2022/04/08 11:58:19 by mypark           ###   ########.fr       */
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
	int	ret;

	//printf("dup2 srcfd dstfd: %d %d\n", srcfd, dstfd);
	ret = dup2(srcfd, dstfd);
	if (ret == -1)
		print_strerror("dup2", strerror(errno));
}
