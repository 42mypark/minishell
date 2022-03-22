/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 23:35:11 by mypark            #+#    #+#             */
/*   Updated: 2022/03/22 16:54:11 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_UTILS_H
# define TOKENIZER_UTILS_H
# include "token.h"
# define BUFFER_SIZE 1024

typedef enum e_tokenizer_state
{
	BLANK,
	SINGLE_QUOTE,
	DOUBLE_QUOTE,
	CHARS,
	SINGLE_META,
	DOUBLE_META
}			t_tokenizer_state;

void				issue_token(t_tokens *tks, char *buf, int *len);
void				push_buffer(char *buf, char input, int *len);
int					is_meta(char c);
int					is_blank(char c);
int					is_parenthesis(char c);
enum e_token		to_enum_token(char *str);
t_tokenizer_state	tokenizer_chars(t_tokens *tks, char *buf, int *len, char input);
t_tokenizer_state	tokenizer_single_meta(t_tokens *tks, char *buf, int *len, char input);
t_tokenizer_state	tokenizer_double_meta(t_tokens *tks, char *buf, int *len, char input);
t_tokenizer_state	tokenizer_double_quote(t_tokens *tks, char *buf, int *len, char input);
t_tokenizer_state	tokenizer_single_quote(t_tokens *tks, char *buf, int *len, char input);

#endif
