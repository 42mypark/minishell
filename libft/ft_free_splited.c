/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_splited.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:20:32 by mypark            #+#    #+#             */
/*   Updated: 2022/03/24 14:42:46 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_free_splited(char **words)
{
	int	wi;

	wi = 0;
	while (words[wi])
		free(words[wi++]);
	free(words[wi]);
	free(words);
}