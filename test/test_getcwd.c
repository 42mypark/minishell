/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_getcwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:43:39 by mypark            #+#    #+#             */
/*   Updated: 2022/03/24 16:48:16 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

int	main(void)
{
	char	*dir_name;
	DIR		*dir_ptr;
	struct dirent *dp;
	int		cnt;
	char	**files;
	
	dir_name = getcwd(NULL, 0);
	dir_ptr = opendir(dir_name);
	if (dir_ptr == NULL)
		printf("ERROR\n");
	dp = readdir(dir_ptr);
	cnt = 0;
	while (dp)
	{
		cnt++;
		printf("%ld\n", dir_ptr->__dd_loc);
		dp = readdir(dir_ptr);
	}
	closedir(dir_ptr);

	files = malloc(sizeof(char *) * (cnt + 1));
	files[cnt] = NULL;
	dir_ptr = opendir(dir_name);
	if (dir_ptr == NULL)
		printf("ERROR\n");
	printf("%ld\n", dir_ptr->__dd_loc);
	dp = readdir(dir_ptr);
	cnt = 0;
	while (dp)
	{
		printf("%ld\n", dir_ptr->__dd_loc);
		//files[cnt++] = ft_strdup(dp->d_namlen);
		dp = readdir(dir_ptr);
	}
	closedir(dir_ptr);
	free(dir_name);
	while (1);
}

//  dirp = opendir(".");
//            if (dirp == NULL)
//                    return (ERROR);
//            len = strlen(name);
//            while ((dp = readdir(dirp)) != NULL) {
//                    if (dp->d_namlen == len && strcmp(dp->d_name, name) == 0) {
//                            (void)closedir(dirp);
//                            return (FOUND);
//                    }
//            }
//            (void)closedir(dirp);
//            return (NOT_FOUND)