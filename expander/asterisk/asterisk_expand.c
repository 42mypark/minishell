/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asterisk_expand.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 02:06:59 by mypark            #+#    #+#             */
/*   Updated: 2022/03/24 20:01:49 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "parse_tree.h"
#include "asterisk_expander_utils.h"
#include "libft.h"
#include "token.h"

void	asterisk_expander(t_tokens *tks, char *format, char **envp)
{
	int			i;
	char		**files;
	t_buffer	buf;
	
	files = dup_filenames();
	i = 0;
	while (files[i])
	{
		if (asterisk_check_format(files[i], format))
		{
			buf.space = files[i];
			buf.len = ft_strlen(buf.space);
			issue_token(tks, &buf);
		}
		i++;
	}
	ft_free_splited(files);
}

void	expand_asterisk(t_parsetree_node *head, char **envp)
{
	expand_tour_tree(head, asterisk_expander, envp);
}
