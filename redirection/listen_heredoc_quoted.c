/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listen_heredoc_quoted.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 20:18:42 by mypark            #+#    #+#             */
/*   Updated: 2022/04/01 03:12:27 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "utils.h"
#include "libft.h"
#include "error.h"

void	listen_heredoc_quoted(char *limiter, int to)
{
	char	*buf;
	int		read_size;
	int		lim_len;

	limiter = ft_strjoin(limiter, "\n");
	lim_len = ft_strlen(limiter);
	buf = malloc(sizeof(char) * (lim_len + 1));
	if (buf == NULL)
		print_malloc_error();
	ft_putstr_fd("> ", 1);
	while (1)
	{
		read_size = read(0, buf, lim_len);
		buf[read_size] = '\0';
		if (is_same(buf, limiter))
			break ;
		write(1, buf, read_size);
		write(to, buf, read_size);
		if (ft_strchr(buf, '\n'))
			ft_putstr_fd("> ", 1);
	}
	free(buf);
	close(to);
}
