/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_same.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:09:58 by mypark            #+#    #+#             */
/*   Updated: 2022/04/12 03:41:32 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "constant.h"

int	is_same(char *s1, char *s2)
{
	if (s1 == FT_NULL || s2 == FT_NULL)
		return (0);
	if (ft_strncmp(s1, s2, -1) == 0)
		return (1);
	return (0);
}
