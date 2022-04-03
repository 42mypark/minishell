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

void	ft_splitfree(char **words)
{
	int	wi;

	wi = 0;
	while (words[wi])
		free(words[wi++]);
	free(words[wi]);
	free(words);
}
