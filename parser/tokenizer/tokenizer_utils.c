/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:44:06 by mypark            #+#    #+#             */
/*   Updated: 2022/03/23 01:00:14 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

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
