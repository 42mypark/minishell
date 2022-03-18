/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 19:49:12 by mypark            #+#    #+#             */
/*   Updated: 2021/12/14 14:50:35 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_size(size_t len, size_t len_s)
{
	if (len_s > len)
		return (len);
	else
		return (len_s);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	len_s;
	size_t	size;

	len_s = ft_strlen(s);
	size = get_size(len, len_s);
	substr = malloc(sizeof(char) * size + 1);
	if (substr == NULL)
		return (NULL);
	if (start > len_s)
	{
		substr[0] = 0;
		return (substr);
	}
	i = 0;
	while (i < size)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[size] = '\0';
	return (substr);
}
