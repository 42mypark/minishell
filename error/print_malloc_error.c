/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_malloc_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:57:10 by mypark            #+#    #+#             */
/*   Updated: 2022/03/23 21:01:11 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_malloc_error(void)
{
	ft_putstr_fd("memory allocation fails.\n", 2);
	exit(1);
}
