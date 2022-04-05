/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 01:46:22 by mypark            #+#    #+#             */
/*   Updated: 2022/04/05 00:51:15 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H
# include "token.h"
# include "utils.h"

typedef enum e_tokenizer_state
{
	T_BLANK,
	T_CHARS,
	T_SINGLE_QUOTE,
	T_DOUBLE_QUOTE,
	T_SINGLE_META,
	T_DOUBLE_META
}			t_tokenizer_state;

typedef struct s_tokenizer
{
	t_tokenizer_state	state;
	t_buffer			*buf;
	void				(*actions[6])(struct s_tokenizer *, char);
	t_tokens			*tokens;
}				t_tokenizer;

enum e_token	to_enum_token(char *str);

#endif
