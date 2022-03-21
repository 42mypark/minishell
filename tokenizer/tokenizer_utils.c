/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 01:09:36 by mypark            #+#    #+#             */
/*   Updated: 2022/03/22 01:40:22 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "tokenizer_utils.h"

int	is_meta(char c)
{
	if (c == '(' || c == ')' || c == '&' \
	 || c == '|' || c == '<' || c == '>')
		return (1);
	return (0);
}

enum e_token	to_enum_token(char *str)
{
	if (ft_strncmp(str, "<", -1) == 0)
		return (IRD);
	if (ft_strncmp(str, ">", -1) == 0)
		return (ORD);
	if (ft_strncmp(str, "<<", -1) == 0)
		return (HRD);
	if (ft_strncmp(str, ">>", -1) == 0)
		return (ARD);
	if (ft_strncmp(str, "|", -1) == 0)
		return (PIPE);
	if (ft_strncmp(str, "&&", -1) == 0)
		return (AND);
	if (ft_strncmp(str, "||", -1) == 0)
		return (OR);
	if (ft_strncmp(str, "(", -1) == 0)
		return (LPT);
	if (ft_strncmp(str, ")", -1) == 0)
		return (RPT);
	return (INVTK);
}

enum e_tokenizer_state	tokenizer_chars(t_tokens *tks, \
										char *buf, int *len, char input)
{
	if (input == ' ' || input == '\t')
	{
		tks->push_tail(tks, new_token(STR, buf));
		*len = 0;
		buf[0] = '\0';
		return (BLANK);
	}
	if (is_meta(input))
	{
		tks->push_tail(tks, new_token(STR, buf));
		buf[0] = input;
		buf[1] = '\0';
		*len = 1;
		return (SINGLE_META);
	}
	buf[(*len)++] = input;
	buf[(*len)] = '\0';
	if (input == '\'')
		return (SINGLE_QUOTE);
	if (input == '\"')
		return (DOUBLE_QUOTE);
	return (CHARS);
}

enum e_tokenizer_state	tokenizer_single_meta(t_tokens *tks, \
										char *buf, int *len, char input)
{
	if (input == ' ' || input == '\t')
	{
		tks->push_tail(tks, new_token(to_enum_token(buf), buf));
		*len = 0;
		buf[0] = '\0';
		return (BLANK);
	}
	if (input != '(' && input != ')' && input == buf[0])
	{
		buf[(*len)++] = input;
		buf[(*len)] = '\0';
		return (DOUBLE_META);
	}
	tks->push_tail(tks, new_token(to_enum_token(buf), buf));
	buf[0] = input;
	buf[1] = '\0';
	*len = 1;
	if (is_meta(input));
		return (SINGLE_META);
	if (input == '\'')
		return (SINGLE_QUOTE);
	if (input == '\"')
		return (DOUBLE_QUOTE);
	return (CHARS);
}

enum e_tokenizer_state	tokenizer_double_meta(t_tokens *tks, \
										char *buf, int *len, char input)
{
	if (input == ' ' || input == '\t')
	{
		tks->push_tail(tks, new_token(to_enum_token(buf), buf));
		*len = 0;
		buf[0] = '\0';
		return (BLANK);
	}
	tks->push_tail(tks, new_token(to_enum_token(buf), buf));
	buf[0] = input;
	buf[1] = '\0';
	*len = 1;
	if (is_meta(input));
		return (SINGLE_META);
	if (input == '\'')
		return (SINGLE_QUOTE);
	if (input == '\"')
		return (DOUBLE_QUOTE);
	return (CHARS);
}
