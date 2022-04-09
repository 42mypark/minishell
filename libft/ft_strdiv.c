/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdiv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 18:47:39 by mypark            #+#    #+#             */
/*   Updated: 2022/04/09 17:51:44 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdiv(char **front, int index)
{
	char	*back;

	back = ft_strdup((*front) + index);
	*front = ft_realloc(*front, index + 1);
	if (*front == 0)
		return (0);
	return (back);
}
