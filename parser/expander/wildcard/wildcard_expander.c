/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_expander.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 02:06:59 by mypark            #+#    #+#             */
/*   Updated: 2022/04/02 16:02:14 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "parse_tree.h"
#include "wildcard_expander_utils.h"
#include "libft.h"
#include "token.h"
#include "expansion_record.h"

void	wildcard_expander(t_tokens *tks, t_token *tk, char **envp)
{
	int			i;
	char		**files;
	char		**formats;
	t_buffer	buf;

	envp++;
	init_buffer(&buf);
	files = dup_filenames();
	formats = wildcard_split(tk);
	if (formats == NULL)
		print_malloc_error();
	i = 0;
	while (files[i])
	{
		if (wildcard_check_format(files[i], tk, formats))
		{
			buf.space = files[i];
			buf.len = ft_strlen(buf.space);
			expansion_record_add_back(&buf.expansion_record, new_expansion_range(0, buf.len));
			issue_token(tks, &buf);
		}
		i++;
	}
	ft_free_splited(formats);
	ft_free_splited(files);
}
