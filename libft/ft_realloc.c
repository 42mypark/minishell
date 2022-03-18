/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 22:38:07 by mypark            #+#    #+#             */
/*   Updated: 2021/12/23 22:38:21 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_realloc(char *original, int desired)
{
	char	*tmp;

	tmp = malloc(sizeof(char) * desired);
	if (tmp == NULL)
		return (NULL);
	tmp[0] = '\0';
	ft_strlcat(tmp, original, desired);
	free(original);
	return (tmp);
}
