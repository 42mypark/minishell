/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strict_opendir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 21:15:13 by mypark            #+#    #+#             */
/*   Updated: 2022/04/12 03:39:24 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "constant.h"
#include <dirent.h>

DIR	*strict_opendir(char *dir_name)
{
	DIR	*dir_ptr;

	dir_ptr = opendir(dir_name);
	if (dir_ptr == FT_NULL)
		print_strerror("open directory", FT_NULL, ERRMSG_OPENDIR);
	return (dir_ptr);
}
