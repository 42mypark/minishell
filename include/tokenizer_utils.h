/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 23:35:11 by mypark            #+#    #+#             */
/*   Updated: 2022/03/24 02:58:40 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_UTILS_H
# define TOKENIZER_UTILS_H
# include "token.h"

typedef enum e_tokenizer_state
{
	T_BLANK,
	T_SINGLE_QUOTE,
	T_DOUBLE_QUOTE,
	T_CHARS,
	T_SINGLE_META,
	T_DOUBLE_META
}			t_tokenizer_state;

enum e_token		to_enum_token(char *str);
t_tokenizer_state	tokenizer_chars(t_tokens *tks, t_buffer *buf, char input);
t_tokenizer_state	tokenizer_single_meta(t_tokens *tks, t_buffer *buf, char input);
t_tokenizer_state	tokenizer_double_meta(t_tokens *tks, t_buffer *buf, char input);
t_tokenizer_state	tokenizer_double_quote(t_tokens *tks, t_buffer *buf, char input);
t_tokenizer_state	tokenizer_single_quote(t_tokens *tks, t_buffer *buf, char input);

#endif
