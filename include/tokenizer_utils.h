/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 23:35:11 by mypark            #+#    #+#             */
/*   Updated: 2022/03/24 01:44:32 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_UTILS_H
# define TOKENIZER_UTILS_H
# include "token.h"

typedef enum e_tokenizer_state
{
	BLANK,
	SINGLE_QUOTE,
	DOUBLE_QUOTE,
	CHARS,
	SINGLE_META,
	DOUBLE_META
}			t_tokenizer_state;

enum e_token		to_enum_token(char *str);
t_tokenizer_state	tokenizer_chars(t_tokens *tks, char *buf, int *len, char input);
t_tokenizer_state	tokenizer_single_meta(t_tokens *tks, char *buf, int *len, char input);
t_tokenizer_state	tokenizer_double_meta(t_tokens *tks, char *buf, int *len, char input);
t_tokenizer_state	tokenizer_double_quote(t_tokens *tks, char *buf, int *len, char input);
t_tokenizer_state	tokenizer_single_quote(t_tokens *tks, char *buf, int *len, char input);

#endif
