/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listen_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 20:18:42 by mypark            #+#    #+#             */
/*   Updated: 2022/04/01 20:28:50 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "utils.h"
#include "libft.h"
#include "expander.h"
#include "error.h"
#include "test.h"
#include "strict.h"

static int	is_env_end(char *str)
{
	while (*str)
	{
		if (!ft_isalnum(*str) && *str != '_' && *str !='$')
			return (1);
		str++;
	}
	return (0);
}

static void	read_env(t_buffer *mbuf, char *rbuf, int lim_len)
{
	int	read_size;

	read_size = read(0, rbuf, lim_len + 1);
	rbuf[read_size] = '\0';
	while (read_size > 0)
	{
		push_buffer_str(mbuf, rbuf);
		if (is_env_end(rbuf))
			break;
		read_size = read(0, rbuf, lim_len +1);
		rbuf[read_size] = '\0';
	}
}

static void	expand_input(t_buffer *mbuf, char *rbuf, int lim_len, char **envp)
{
	t_tokens	*tks;
	char		**expanded;
	int			i;

	read_env(mbuf, rbuf, lim_len);
	tks = new_tokens();
	env_expander(tks, mbuf->space, envp);
	clear_buffer(mbuf);
	expanded = tokens_to_splited(tks);
	i = 0;
	while(expanded[i])
	{
		push_buffer_str(mbuf, expanded[i]);
		i++;
	}
	free_tokens(tks);
	ft_free_splited(expanded);
}

void	listen_heredoc(char *limiter, int to, char **envp)
{
	t_buffer	mbuf;
	char		*rbuf;
	int			read_size;
	int			lim_len;

	init_buffer(&mbuf);
	limiter = ft_strjoin(limiter, "\n");
	lim_len = ft_strlen(limiter);
	rbuf = strict_malloc(sizeof(char), lim_len + 1);
	ft_putstr_fd("> ", 1);
	while (1)
	{
		read_size = read(0, rbuf, lim_len);
		rbuf[read_size] = '\0';
		if (is_same(rbuf, limiter))
			break ;
		push_buffer_str(&mbuf, rbuf);
		if (ft_strchr(rbuf, '$'))
			expand_input(&mbuf, rbuf, lim_len, envp);
		if (ft_strrchr(rbuf, '\n'))
			ft_putstr_fd("> ", 1);
	}
	write(to, mbuf.space, mbuf.len);
	reset_buffer(&mbuf);
	free(limiter);
	free(rbuf);
	strict_close(to);
}
