/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strict_opendir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 21:15:13 by mypark            #+#    #+#             */
/*   Updated: 2022/04/10 21:29:00 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include <dirent.h>

DIR	*strict_opendir(char *dir_name)
{
	DIR	*dir_ptr;

	dir_ptr = opendir(dir_name);
	if (dir_ptr == NULL)
		print_strerror("open directory", NULL, "cannot be accessed.");
	return (dir_ptr);
}
