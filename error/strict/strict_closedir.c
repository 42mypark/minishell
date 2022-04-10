/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strict_closedir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 21:15:13 by mypark            #+#    #+#             */
/*   Updated: 2022/04/10 21:28:20 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include <dirent.h>
#include <errno.h>
#include <string.h>

void	strict_closedir(DIR *dir_ptr)
{
	int	ret;

	ret = closedir(dir_ptr);
	if (ret == -1)
		print_strerror("close directory", NULL, strerror(errno));
}
