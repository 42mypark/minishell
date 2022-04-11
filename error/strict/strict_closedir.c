/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strict_closedir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 21:15:13 by mypark            #+#    #+#             */
/*   Updated: 2022/04/12 03:41:00 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "constant.h"
#include <dirent.h>
#include <errno.h>
#include <string.h>

void	strict_closedir(DIR *dir_ptr)
{
	int	ret;

	ret = closedir(dir_ptr);
	if (ret == -1)
		print_strerror("close directory", FT_NULL, strerror(errno));
}
