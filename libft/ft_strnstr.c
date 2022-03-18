/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 19:33:26 by mypark            #+#    #+#             */
/*   Updated: 2021/12/14 15:04:09 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	len_needle;

	if (needle[0] == '\0')
		return ((char *)haystack);
	len_needle = ft_strlen(needle);
	i = 0;
	while (haystack[i] && i + len_needle <= len)
	{
		if (ft_strncmp(needle, haystack + i, len_needle) == 0)
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
