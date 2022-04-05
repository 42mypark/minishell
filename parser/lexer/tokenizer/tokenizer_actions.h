/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_actions.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 23:35:11 by mypark            #+#    #+#             */
/*   Updated: 2022/04/05 00:52:50 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_ACTIONS_H
# define TOKENIZER_ACTIONS_H
# include "tokenizer.h"

void	tokenizer_chars(t_tokenizer *tokenizer, char input);
void	tokenizer_double_quote(t_tokenizer *tokenizer, char input);
void	tokenizer_single_quote(t_tokenizer *tokenizer, char input);
void	tokenizer_single_meta(t_tokenizer *tokenizer, char input);
void	tokenizer_double_meta(t_tokenizer *tokenizer, char input);

#endif
