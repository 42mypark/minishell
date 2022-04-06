/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:47:39 by mypark            #+#    #+#             */
/*   Updated: 2022/04/06 19:59:38 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, int n)
{
	char	*dup;

	dup = malloc(sizeof(char) * n + 1);
	if (dup == NULL)
		return (NULL);
	ft_strlcpy(dup, s1, n + 1);
	return (dup);
}
