/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_epdr_actions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 02:59:21 by mypark            #+#    #+#             */
/*   Updated: 2022/03/27 13:59:44 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wildcard_expander_utils.h"
#include "utils.h"
#include "test.h"

t_wildcard_epdr_state	wildcard_epdr_compare(char **splited_format, \
											char *file, int *wc, int *fi)
{
	int	len;

	len = ft_strlen(splited_format[*wc]);
	if (ft_strncmp(file + (*fi), splited_format[*wc], len) == 0)
	{
		(*fi) += len;
		(*wc)++;
		return (A_WILDCARD);
	}
	else
		return (A_REJECT);
}

t_wildcard_epdr_state	wildcard_epdr_wildcard(char **splited_format, \
											char *file, int *wc, int *fi)
{
	char	escape_char;

	escape_char = splited_format[*wc][0];
	if (file[*fi] == escape_char)
		return (A_COMPARE);
	else
	{
		(*fi)++;
		return (A_WILDCARD);
	}
}
