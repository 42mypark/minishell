/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_expander.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 02:06:59 by mypark            #+#    #+#             */
/*   Updated: 2022/03/26 20:46:22 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "parse_tree.h"
#include "wildcard_expander_utils.h"
#include "libft.h"
#include "token.h"

static void	wildcard_expander(t_tokens *tks, char *format, char **envp)
{
	int			i;
	char		**files;
	t_buffer	buf;

	init_buffer(&buf);
	files = dup_filenames();
	i = 0;
	while (files[i])
	{
		if (wildcard_check_format(files[i], format))
		{
			buf.space = files[i];
			buf.len = ft_strlen(buf.space);
			add_ep_rec_back(&buf.ep_rec, new_ep_range(0, buf.len));
			issue_token(tks, &buf);
		}
		i++;
	}
	ft_free_splited(files);
}

t_tokens	*expand_token_wildcard(t_token *tk, char **envp)
{
	t_tokens	*tks;
	char		*str;

	tks = new_tokens();
	wildcard_expander(tks, tk->content, envp);
	if (tks->head == NULL)
		tks->push_tail(tks, tk);
	else
		free_token(tk);
	return (tks);
}

void	expand_wildcard(t_parsetree_node *head, char **envp)
{
	expand_tour_tree(head, expand_token_wildcard, envp);
}
