/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_check_format.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:38:09 by mypark            #+#    #+#             */
/*   Updated: 2022/03/27 13:53:01 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "wildcard_expander_utils.h"
#include "test.h"

static void	wildcard_epdr_init(\
	t_wildcard_epdr_state *s, \
	t_wildcard_epdr_state (*actions[2])(char **, char *, int *, int *), \
	char *format, char ***splited_format)
{
	if (format[0] == '*')
		*s = A_WILDCARD;
	else
		*s = A_COMPARE;
	actions[0] = wildcard_epdr_wildcard;
	actions[1] = wildcard_epdr_compare;
	*splited_format = ft_split(format, '*');
	if (*splited_format == NULL)
		print_malloc_error();
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

int	wildcard_check_format(char *file, char *format)
{
	char					**splited_format;
	int						fi;
	int						wc;
	t_wildcard_epdr_state	s;
	t_wildcard_epdr_state	(*actions[4])(char **, char *, int *, int *);

	wildcard_epdr_init(&s, actions, format, &splited_format);
	wc = 0;
	fi = 0;
	while (file[fi] && splited_format[wc])
	{
		s = actions[s](splited_format, file, &wc, &fi);
		if (s == A_REJECT)
		{
			ft_free_splited(splited_format);
			return (0);
		}
	}
	if (is_success(format, file, fi, splited_format[wc]))
	{
		ft_free_splited(splited_format);
		return (1);
	}
	ft_free_splited(splited_format);
	return (0);
}
