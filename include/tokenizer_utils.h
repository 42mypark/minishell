/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 23:35:11 by mypark            #+#    #+#             */
/*   Updated: 2022/03/22 01:34:46 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H
# include "token.h"

enum e_tokenizer_state
{
	BLANK,
	SINGLE_QUOTE,
	DOUBLE_QUOTE,
	CHARS,
	SINGLE_META,
	DOUBLE_META
};

int						is_meta(char c);
enum e_tokenizer_state	tokenizer_chars(t_tokens *tks, char *buf, int *len, char input);
enum e_tokenizer_state	tokenizer_single_meta(t_tokens *tks, char *buf, int *len, char input);
enum e_tokenizer_state	tokenizer_double_meta(t_tokens *tks, char *buf, int *len, char input);

#endif
