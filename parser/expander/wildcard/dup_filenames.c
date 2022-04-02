/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_filenames.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:45:08 by mypark            #+#    #+#             */
/*   Updated: 2022/04/01 20:34:49 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "error.h"
#include "strict.h"
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>

static int	count_files(DIR *dir_ptr)
{
	int				cnt;
	struct dirent	*dp;

	dp = readdir(dir_ptr);
	cnt = 0;
	while (dp)
	{
		cnt++;
		dp = readdir(dir_ptr);
	}
	return (cnt);
}

static char	**put_on_files(DIR *dir_ptr, int file_cnt)
{
	char			**files;
	struct dirent	*dp;
	int				i;

	files = strict_malloc(sizeof(char *), (file_cnt + 1));
	files[file_cnt] = NULL;
	i = 0;
	dp = readdir(dir_ptr);
	while (dp && i < file_cnt)
	{
		files[i++] = ft_strdup(dp->d_name);
		dp = readdir(dir_ptr);
	}
	return (files);
}

char	**dup_filenames(void)
{
	char	*dir_name;
	DIR		*dir_ptr;
	int		file_cnt;
	char	**files;

	dir_name = getcwd(NULL, 0);
	dir_ptr = opendir(dir_name);
	if (dir_ptr == NULL)
		print_strerror("DIR OPEN", "cannot be accessed");
	file_cnt = count_files(dir_ptr);
	closedir(dir_ptr);
	dir_ptr = opendir(dir_name);
	files = put_on_files(dir_ptr, file_cnt);
	closedir(dir_ptr);
	free(dir_name);
	return (files);
}
