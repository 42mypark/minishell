/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strict_open.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:47:13 by mypark            #+#    #+#             */
/*   Updated: 2022/04/03 18:32:38 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include "error.h"

int	strict_open(char *filename, int oflag, int right)
{
	int	ret;

	ret = open(filename, oflag, right);
	if (ret == -1)
		print_strerror("open", strerror(errno));
	return (ret);
}
