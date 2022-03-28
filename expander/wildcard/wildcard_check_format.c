/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_check_format.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:38:09 by mypark            #+#    #+#             */
/*   Updated: 2022/03/28 22:05:20 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "wildcard_expander_utils.h"
#include "test.h"

static void	wildcard_epdr_init(\
	t_wildcard_epdr_state *s, \
	t_wildcard_epdr_state (*actions[2])(char **, char *, int *, int *), \
	t_token *tk)
{
	char	*format;

	format = tk->content;
	if (format[0] == '*')
		*s = A_WILDCARD;
	else
		*s = A_COMPARE;
	actions[0] = wildcard_epdr_wildcard;
	actions[1] = wildcard_epdr_compare;
}

static int	is_success(char *format, char *file, int fi, char *last_format)
{
	int	last_char;

	last_char = ft_strlen(format) - 1;
	if (last_format == NULL && format[last_char] == '*')
		return (1);
	if (last_format == NULL && fi == (int)ft_strlen(file))
		return (1);
	return (0);
}

int	wildcard_check_format(char *file, t_token *tk, char **formats)
{
	int						fi;
	int						wc;
	t_wildcard_epdr_state	s;
	t_wildcard_epdr_state	(*actions[2])(char **formats, char *file, int *wc, int *fi);

	wildcard_epdr_init(&s, actions, tk);
	wc = 0;
	fi = 0;
	while (file[fi] && formats[wc])
	{
		s = actions[s](formats, file, &wc, &fi);
		if (s == A_REJECT)
			return (0);
	}
	if (is_success(tk->content, file, fi, formats[wc]))
		return (1);
	return (0);
}
