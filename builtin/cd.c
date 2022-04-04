/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:07:41 by mypark            #+#    #+#             */
/*   Updated: 2022/04/04 19:15:32 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "error.h"
#include <errno.h>
#include <string.h>

int	builtin_cd(char *dir, char **envp)
{
	int		ret;
	char	*home;

	if (dir == NULL)
	{
		home = dupenv("HOME", envp);
		ret = chdir(home);
		if (ret == -1)
		{
			print_strerror("builtin", strerror(errno));
			return (1);
		}
		free(home);
		return (0);
	}
	ret = chdir(dir);
	if (ret == -1)
	{
		print_strerror("builtin", strerror(errno));
		return (1);
	}
	return (0);
}