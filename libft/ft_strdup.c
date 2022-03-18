/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:47:39 by mypark            #+#    #+#             */
/*   Updated: 2021/12/13 19:47:41 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len_s1;
	char	*dup;

	len_s1 = ft_strlen(s1);
	dup = malloc(sizeof(char) * len_s1 + 1);
	if (dup == NULL)
		return (NULL);
	ft_strlcpy(dup, s1, len_s1 + 1);
	return (dup);
}
