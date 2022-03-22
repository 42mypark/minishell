/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_chars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:44:06 by mypark            #+#    #+#             */
/*   Updated: 2022/03/23 01:00:45 by mypark           ###   ########.fr       */
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

int	is_redir(char c)
{
	if (c == '<' || c == '>')
		return (1);
	return (0);
}