/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asterisk_check_format.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:38:09 by mypark            #+#    #+#             */
/*   Updated: 2022/03/24 21:53:55 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "asterisk_expander_utils.h"
#include "test.h"

static void	asterisk_epdr_init(\
	t_asterisk_epdr_state (*behav[2])(char **, char *, int *, int *))
{
	behav[0] = asterisk_epdr_asterisk;
	behav[1] = asterisk_epdr_compare;
}

static int	is_success(char *format, char *file, int fi, char *last_format)
{
	int	last_char;

	last_char = ft_strlen(format) - 1;
	if (last_format == NULL && format[last_char] == '*')
		return (1);
	if (last_format == NULL && fi == ft_strlen(file))
		return (1);
	return (0);
}

int	asterisk_check_format(char *file, char *format)
{
	char					**splited_format;
	int						fi;
	int						wc;
	t_asterisk_epdr_state	s;
	t_asterisk_epdr_state	(*behav[4])(char **, char *, int *, int *);

	asterisk_epdr_init(behav);
	splited_format = ft_split(format, '*');
	if (splited_format == NULL)
		print_malloc_error();
	s = A_COMPARE;
	if (format[0] == '*')
		s = A_ASTERISK;
	wc = 0;
	fi = 0;
	while (file[fi] && splited_format[wc])
	{
		s = behav[s](splited_format, file, &wc, &fi);
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
