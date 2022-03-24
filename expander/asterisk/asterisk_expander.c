/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asterisk_expander.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 02:06:59 by mypark            #+#    #+#             */
/*   Updated: 2022/03/25 01:02:12 by mypark           ###   ########.fr       */
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

t_tokens	*expand_token_asterisk(t_token *tk, char **envp)
{
	t_tokens	*tks;
	char		*str;

	tks = new_tokens();
	asterisk_expander(tks, tk->content, envp);
	if (tks->head == NULL)
		tks->push_tail(tks, tk);
	else
		free_token(tk);
	return (tks);
}

void	expand_asterisk(t_parsetree_node *head, char **envp)
{
	expand_tour_tree(head, expand_token_asterisk, envp);
}
