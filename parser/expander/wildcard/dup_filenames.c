/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_filenames.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:45:08 by mypark            #+#    #+#             */
/*   Updated: 2022/04/12 03:42:21 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "error.h"
#include "strict.h"
#include "constant.h"
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>

static int	count_files(DIR *dir_ptr)
{
	int				cnt;
	struct dirent	*dp;

	if (dir_ptr == FT_NULL)
		return (0);
	dp = readdir(dir_ptr);
	cnt = 0;
	while (dp)
	{
		cnt++;
		dp = readdir(dir_ptr);
	}
	return (cnt);
}

static char	**make_files(DIR *dir_ptr, int file_cnt)
{
	char			**files;
	struct dirent	*dp;
	int				i;

	if (dir_ptr == FT_NULL)
		return (FT_NULL);
	files = strict_malloc(sizeof(char *), (file_cnt + 1));
	files[file_cnt] = FT_NULL;
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

	files = FT_NULL;
	dir_name = getcwd(FT_NULL, 0);
	if (dir_name == 0)
		print_strerror("getcwd", FT_NULL, strerror(errno));
	dir_ptr = strict_opendir(dir_name);
	file_cnt = count_files(dir_ptr);
	strict_closedir(dir_ptr);
	dir_ptr = strict_opendir(dir_name);
	files = make_files(dir_ptr, file_cnt);
	strict_closedir(dir_ptr);
	free(dir_name);
	return (files);
}
