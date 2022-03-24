/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asterisk_epdr_behavior.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 02:59:21 by mypark            #+#    #+#             */
/*   Updated: 2022/03/24 14:33:58 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asterisk_expander_utils.h"
#include "utils.h"

t_asterisk_epdr_state	asterisk_epdr_compare(char **splited_format, char *file, int *wc, int *fi)
{
	int	len;

	len = ft_strlen(splited_format[*wc]);
	if (ft_strncmp(file[*fi], splited_format[*wc], len) == 0)
	{
		*fi += len;
		*wc++;
		return (A_ASTERISK);
	}
	else
		return (A_REJECT);
}

t_asterisk_epdr_state	asterisk_epdr_asterisk(char **splited_format, char *file, int *wc, int *fi)
{
	char	escape_char;

	escape_char = splited_format[*wc][0];
	if (file[*fi] == escape_char)
		return (A_COMPARE);
	else
		return (A_ASTERISK);
}