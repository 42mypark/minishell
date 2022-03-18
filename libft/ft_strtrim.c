/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 20:27:05 by mypark            #+#    #+#             */
/*   Updated: 2021/12/03 20:42:35 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*only_set(void)
{
	char	*tmp;

	tmp = malloc(sizeof(char *));
	tmp[0] = '\0';
	return (tmp);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len_s1;
	int		len;
	int		s;
	int		e;

	len_s1 = ft_strlen(s1);
	s = 0;
	while (s < len_s1)
	{
		if (!is_in_set(s1[s], set))
			break ;
		s++;
	}
	e = len_s1 - 1;
	while (e >= 0)
	{
		if (!is_in_set(s1[e], set))
			break ;
		e--;
	}
	len = e - s + 1;
	if (len < 0)
		return (only_set());
	return (ft_substr(s1, s, len));
}
