/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:59:00 by mypark            #+#    #+#             */
/*   Updated: 2021/12/03 20:50:40 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int x)
{
	if (x == -2147483648)
		return (1);
	if (x > 0)
		return (x);
	return (x * -1);
}

static void	ft_strrev(char *s, int len)
{
	int		i;
	int		j;
	char	tmp;

	len = ft_strlen(s);
	i = 0;
	while (i < (len / 2))
	{
		j = len - i - 1;
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
		i++;
	}
}

char	*alloc_zero(void)
{
	char	*tmp;

	tmp = malloc(sizeof(char) * 2);
	tmp[0] = '0';
	tmp[1] = '\0';
	return (tmp);
}

char	*ft_itoa(int n)
{
	char	arr[13];
	int		len;
	int		sign;

	if (n == 0)
		return (alloc_zero());
	sign = 0;
	if (n < 0)
		sign = -1;
	len = 0;
	while (ft_abs(n) > 0)
	{
		arr[len++] = '0' + ft_abs(n % 10);
		n /= 10;
	}
	if (sign == -1)
		arr[len++] = '-';
	arr[len] = '\0';
	ft_strrev(arr, len);
	return (ft_strdup(arr));
}
