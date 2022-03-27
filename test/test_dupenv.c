/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_dupenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:32:10 by mypark            #+#    #+#             */
/*   Updated: 2022/03/27 14:02:07 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_dupenv(char *target, char **envp)
{
	int	ei;
	int	len;

	if (target == NULL || envp == NULL)
		return (ft_strdup(""));
	ei = 0;
	len = ft_strlen(target);
	while (envp[ei])
	{
		if (ft_strncmp(target, envp[ei], len) == 0)
			return (ft_strdup(&envp[ei][len + 1]));
		ei++;
	}
	return (ft_strdup(""));
}

int	main(int argc, char **argv, char **envp)
{
	char	*path;

	path = ft_dupenv("PATH", envp);
	ft_putendl_fd(path, 1);
	free(path);
}
