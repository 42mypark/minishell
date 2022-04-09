/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_expander.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 02:06:59 by mypark            #+#    #+#             */
/*   Updated: 2022/04/09 16:29:00 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "libft.h"
#include "token.h"
#include "utils.h"
#include "wildcard_expander.h"
#include "expansion_record.h"

static void	filename_to_token(t_tokens *tks, char *filename)
{
	t_buffer			buf;
	t_expansion_range	*range;

	init_buffer(&buf);
	buf.space = filename;
	buf.len = ft_strlen(buf.space);
	range = new_expansion_range(0, buf.len);
	expansion_record_add_back(&buf.expansion_record, range);
	issue_token(tks, &buf);
}

void	wildcard_expander(t_tokens *tks, t_token *tk)
{
	int			i;
	char		**filenames;
	char		**patterns;
	char		*pattern_raw;

	filenames = dup_filenames();
	if (filenames == NULL)
		return ;
	pattern_raw = tk->content;
	patterns = wildcard_split(tk);
	if (patterns == NULL)
		print_malloc_error();
	i = -1;
	while (filenames[++i])
	{
		if (filenames[i][0] == '.' && pattern_raw[0] != '.')
			continue ;
		if (wildcard_match(filenames[i], pattern_raw, patterns))
			filename_to_token(tks, filenames[i]);
	}
	ft_splitfree(patterns);
	ft_splitfree(filenames);
}
