/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_expander_utils.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 23:35:11 by mypark            #+#    #+#             */
/*   Updated: 2022/03/25 01:12:16 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_EXPANDER_UTILS_H
# define ENV_EXPANDER_UTILS_H
# include "token.h"
# include "parse_tree.h"

typedef enum e_env_epdr_state
{
	E_CHARS,
	E_SINGLE_QUOTE,
	E_DOUBLE_QUOTE,
	E_EXPAND,
	E_DQ_EXPAND
}			t_env_epdr_state;

t_env_epdr_state	env_epdr_chars(t_tokens *tks, t_buffer *buf, char input, char **envp);
t_env_epdr_state	env_epdr_double_quote(t_tokens *tks, t_buffer *buf, char input, char **envp);
t_env_epdr_state	env_epdr_single_quote(t_tokens *tks, t_buffer *buf, char input, char **envp);
t_env_epdr_state	env_epdr_expand(t_tokens *tks, t_buffer *buf, char input, char **envp);
t_env_epdr_state	env_epdr_dq_expand(t_tokens *tks, t_buffer *buf, char input, char **envp);
void				expand_tour_tree(t_parsetree_node *node, t_tokens *(*todo)(t_token *, char **), char **envp);
char				*dupenv(char *target, char **envp);

#endif
