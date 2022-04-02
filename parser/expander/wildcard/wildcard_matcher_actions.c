/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_matcher_actions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 00:18:12 by mypark            #+#    #+#             */
/*   Updated: 2022/03/29 00:56:25 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wildcard_expander_utils.h"
#include "utils.h"
#include "test.h"

t_wildcard_matcher_state	wildcard_matcher_compare(char **splited_format, \
											char *file, int *wc, int *fi)
{
	int	len;

	len = ft_strlen(splited_format[*wc]);
	if (ft_strncmp(file + (*fi), splited_format[*wc], len) == 0)
	{
		(*fi) += len;
		(*wc)++;
		return (WM_WILDCARD);
	}
	else
		return (WM_REJECT);
}

t_wildcard_matcher_state	wildcard_matcher_wildcard(char **splited_format, \
											char *file, int *wc, int *fi)
{
	char	escape_char;

	escape_char = splited_format[*wc][0];
	if (file[*fi] == escape_char)
		return (WM_COMPARE);
	else
	{
		(*fi)++;
		return (WM_WILDCARD);
	}
}
