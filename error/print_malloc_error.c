/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_malloc_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:57:10 by mypark            #+#    #+#             */
/*   Updated: 2022/04/22 08:29:01 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strict.h"
#include <stdlib.h>

void	print_malloc_error(void)
{
	strict_putstr_fd("memory allocation fails.\n", 2);
	exit(1);
}
