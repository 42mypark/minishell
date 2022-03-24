/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_expander.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 02:06:59 by mypark            #+#    #+#             */
/*   Updated: 2022/03/25 01:32:46 by mypark           ###   ########.fr       */
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
	buf->cnt = 0;
	buf->len = 0;
	buf->space = 0;
}

static void	env_expander(t_tokens *tks, char *str, char **envp)
{
	t_buffer			buf;
	t_env_epdr_state	s;
	t_env_epdr_state	(*actions[5])(t_tokens *, t_buffer *, char, char **);

	env_epdr_init(actions, &buf);
	s = E_CHARS;
	while (*str)
	{
		expand_buffer(&buf);
		s = actions[s](tks, &buf, *str, envp);
		str++;
	}
	if (s == E_EXPAND)
		actions[E_EXPAND](tks, &buf, '\0', envp);
	if (buf.len)
		issue_token(tks, &buf);
	reset_buffer(&buf);
}

t_tokens	*expand_token_env(t_token *tk, char **envp)
{
	t_tokens	*tks;
	char		*str;

	tks = new_tokens();
	env_expander(tks, tk->content, envp);
	if (tks->head == NULL)
		tks->push_tail(tks, tk);
	else
		free_token(tk);
	return (tks);
}

void	expand_env(t_parsetree_node *head, char **envp)
{
	expand_tour_tree(head, expand_token_env, envp);
}
