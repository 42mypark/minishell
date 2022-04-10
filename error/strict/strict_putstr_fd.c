/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    strict_putstr_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:47:13 by mypark            #+#    #+#             */
/*   Updated: 2022/04/10 20:59:14 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "strict.h"
#include "libft.h"

void	strict_putstr_fd(char *str, int fd)
{
	int	len;

	len = ft_strlen(str);
	strict_write(fd, str, len);
}
