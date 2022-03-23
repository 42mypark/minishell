/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_expander_utils.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 23:35:11 by mypark            #+#    #+#             */
/*   Updated: 2022/03/24 03:02:00 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_EXPANDER_UTILS_H
# define ENV_EXPANDER_UTILS_H
# include "token.h"

typedef enum e_env_epdr_state
{
	E_CHARS,
	E_SINGLE_QUOTE,
	E_DOUBLE_QUOTE,
	E_EXPAND,
	E_DQ_EXPAND
}			t_env_epdr_state;

char	*dupenv(char *target, char **envp);
t_env_epdr_state	env_epdr_chars(t_tokens *tks, t_buffer *buf, char input, char **envp);
t_env_epdr_state	env_epdr_double_quote(t_tokens *tks, t_buffer *buf, char input, char **envp);
t_env_epdr_state	env_epdr_single_quote(t_tokens *tks, t_buffer *buf, char input, char **envp);
t_env_epdr_state	env_epdr_expand(t_tokens *tks, t_buffer *buf, char input, char **envp);
t_env_epdr_state	env_epdr_dq_expand(t_tokens *tks, t_buffer *buf, char input, char **envp);

#endif
