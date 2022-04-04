/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitfree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:20:32 by mypark            #+#    #+#             */
/*   Updated: 2022/03/27 13:56:07 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	**ft_splitdup(char **old_words)
{
	char	**new_words;
	int		count;
	int		i;

	count = ft_wordcount(old_words);
	new_words = malloc(sizeof(char *) * (count + 1));
	if (new_words == 0)
		return (0);
	new_words[count] = 0;
	i = 0;
	while (old_words[i])
	{
		new_words[i] = ft_strdup(old_words[i]);
		i++;
	}
	return (new_words);
}
