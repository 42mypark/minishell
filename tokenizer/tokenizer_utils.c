/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:44:06 by mypark            #+#    #+#             */
/*   Updated: 2022/03/22 21:26:38 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

int	is_blank(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int	is_parenthesis(char c)
{
	if (c == '(' || c == ')')
		return (1);
	return (0);
}

int	is_meta(char c)
{
	if (c == '(' || c == ')' || c == '&' \
	 || c == '|' || c == '<' || c == '>')
		return (1);
	return (0);
}

int	is_bool(char c)
{
	if (c == '|' || c == '&')
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
	if (ft_strncmp(str, "&", -1) == 0)
		return (INVALID);
	return (STR);
}
