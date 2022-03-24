/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_filenames.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:45:08 by mypark            #+#    #+#             */
/*   Updated: 2022/03/24 17:07:42 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft"
#include "error.h"
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

static char	**put_on_files(char *dir_name, DIR *dir_ptr, int file_cnt)
{
	char			**files;
	struct dirent	*dp;
	int				i;

	files = malloc(sizeof(char *) * (file_cnt + 1));
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

char	**dup_filenames()
{
	char	*dir_name;
	DIR		*dir_ptr;
	int		file_cnt;
	char	**files;
	
	dir_name = getcwd(NULL, 0);
	dir_ptr = opendir(dir_name);
	if (dir_ptr == NULL)
		print_strerror("cannot be accessed");
	file_cnt = count_files(dir_ptr);
	dir_ptr->__dd_loc = 0;
	files = put_on_files(dir_name, dir_ptr, file_cnt);
	closedir(dir_ptr);
	free(dir_name);
	return (files);
}