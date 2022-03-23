/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dupenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 19:20:09 by mypark            #+#    #+#             */
/*   Updated: 2022/03/23 19:20:10 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_dupenv(char *target, char **envp)
{
	int	ei;
	int	len;

	if(target == NULL || envp == NULL)
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