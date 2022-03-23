/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_expand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 02:06:59 by mypark            #+#    #+#             */
/*   Updated: 2022/03/24 04:05:18 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_tree.h"
#include "utils.h"
#include "env_expander_utils.h"

void	env_epdr_init(\
	t_env_epdr_state (*behav[5])(t_tokens *, t_buffer *, char), \
	t_buffer *buf)
{
	behav[0] = env_epdr_chars;
	behav[1] = env_epdr_single_quote;
	behav[2] = env_epdr_double_quote;
	behav[3] = env_epdr_expand;
	behav[4] = env_epdr_dq_expand;
	buf->cnt = 0;
	buf->len = 0;
	buf->space = ft_calloc(1, 1);
	if (buf->space == NULL)
		print_malloc_error();
}

void	env_expander(t_tokens *tks, char *str, char **envp)
{
	t_buffer			buf;
	t_env_epdr_state	s;
	t_env_epdr_state	(*behavior[5])(t_tokens *, t_buffer *, char, char **);

	env_epdr_init(behavior, &buf);
	s = E_CHARS;
	while (*str)
	{
		if (buf.len == buf.cnt * BUFFER_SIZE)
			buf.space = ft_realloc(buf.space, (++buf.cnt) * BUFFER_SIZE);
		if (buf.space == NULL)
			print_malloc_error();
		s = behavior[s](tks, &buf, *str, envp);
		str++;
	}
	if (buf.len)
		issue_token(tks, &buf);
	free(buf.space);
	return (1);
}

void expand_env(t_parsetree_node *head, char **envp)
{
	expand_tour_tree(head, env_expander, envp);
}
