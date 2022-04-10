/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_strerror.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:57:10 by mypark            #+#    #+#             */
/*   Updated: 2022/04/10 21:06:00 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "strict.h"
#include <errno.h>

void	print_strerror(char *func, char *arg, char *msg)
{
	if (func)
	{
		strict_putstr_fd(func, 2);
		strict_putstr_fd(": ", 2);
	}
	if (arg)
	{
		strict_putstr_fd(arg, 2);
		strict_putstr_fd(": ", 2);
	}
	strict_putstr_fd(msg, 2);
	strict_putstr_fd("\n", 2);
}
