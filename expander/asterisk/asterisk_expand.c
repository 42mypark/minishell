/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asterisk_expand.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 02:06:59 by mypark            #+#    #+#             */
/*   Updated: 2022/03/24 17:15:05 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "parse_tree.h"
#include "asterisk_expander_utils.h"
#include "libft.h"

void	asterisk_expander(t_tokens *tks, char *format, char **envp)
{
	int		i;
	char	**files;
	
	files = dup_filenames();
	i = 0;
	while (files[i])
	{
		if(check_format(files[i], format))
			issue_token(tks, files[i]);
		i++;
	}
	ft_free_splited(files);
}

void	expand_asterisk(t_parsetree_node *head, char **envp)
{
	expand_tour_tree(head, asterisk_expander, envp);
}
