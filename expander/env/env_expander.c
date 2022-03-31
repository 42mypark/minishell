/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_expander.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 02:06:59 by mypark            #+#    #+#             */
/*   Updated: 2022/03/31 22:02:30 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_tree.h"
#include "utils.h"
#include "env_expander_utils.h"
#include "test.h"

static void	env_epdr_init(\
	t_env_epdr_state (*actions[5])(t_tokens *, t_buffer *, char, char **), \
	t_buffer *buf)
{
	actions[0] = env_epdr_chars;
	actions[1] = env_epdr_single_quote;
	actions[2] = env_epdr_double_quote;
	actions[3] = env_epdr_expand;
	actions[4] = env_epdr_dq_expand;
	init_buffer(buf);
}

void	env_expander(t_tokens *tks, char *str, char **envp)
{
	t_buffer			buf;
	t_env_epdr_state	s;
	t_env_epdr_state	(*actions[5])(t_tokens *, t_buffer *, char, char **);

	env_epdr_init(actions, &buf);
	s = E_CHARS;
	while (*str)
	{
		s = actions[s](tks, &buf, *str, envp);
		str++;
	}
	if (s == E_EXPAND)
	{
		actions[E_EXPAND](tks, &buf, '\0', envp);
		ep_rec_add_back(&buf.ep_rec, new_ep_range(buf.start, buf.len));
	}
	if (buf.len)
		issue_token(tks, &buf);
	reset_buffer(&buf);
}
