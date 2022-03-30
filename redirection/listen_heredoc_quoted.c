/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listen_heredoc_quoted.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 20:18:42 by mypark            #+#    #+#             */
/*   Updated: 2022/03/31 00:49:05 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "utils.h"
#include "libft.h"

static int	is_same(char *s1, char *s2)
{
	if (ft_strncmp(s1, s2, -1) == 0)
		return (1);
	return (0);
}

void	listen_heredoc_quoted(char *limiter, int to)
{
	char	buf[BUFFER_SIZE + 1];
	int		read_size;

	limiter = ft_strjoin(limiter, "\n");
	while (1)
	{
		ft_putstr_fd("> ", 1);
		read_size = read(0, buf, BUFFER_SIZE);
		buf[read_size] = '\0';
		if (is_same(buf, limiter))
			break ;
		write(to, buf, read_size);
	}
}
