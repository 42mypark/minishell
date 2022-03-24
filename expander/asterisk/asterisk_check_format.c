/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asterisk_check_format.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:38:09 by mypark            #+#    #+#             */
/*   Updated: 2022/03/24 14:39:46 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "asterisk_expander_utils.h"

static void	asterisk_epdr_init(\
	t_asterisk_epdr_state (*behav[4])(char **, char *, int *, int *))
{
	behav[0] = 0;
	behav[1] = 0;
	behav[2] = asterisk_epdr_asterisk;
	behav[3] = asterisk_epdr_compare;
}

static int	is_success(char *format, char *file, int fi)
{
	int	last;

	last = ft_strlen(format) - 1;
	if (format[last] == '*' || fi == ft_strlen(file))
		return (A_SUCCESS);
	return (A_REJECT);
}

int	asterisk_check_format(char *file, char *format)
{
	char					**splited_format;
	int						fi;
	int						wc;
	t_asterisk_epdr_state	s;
	t_asterisk_epdr_state	(*behav[4])(char **, char *, int *, int *);

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
		if (s == A_REJECT)
		{
			ft_free_splited(splited_format);
			return (A_REJECT);
		}
		s = behav[s](splited_format, file, &wc, &fi);	
		fi++;
	}
	ft_free_splited(splited_format);
	if (is_success(format, file, fi))
		return (A_SUCCESS);
	return (A_REJECT);
}
