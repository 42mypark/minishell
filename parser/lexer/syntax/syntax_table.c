/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 17:39:42 by mypark            #+#    #+#             */
/*   Updated: 2022/04/10 17:41:57 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strict.h"
#include <stdlib.h>

static int	**copy_table(const char (*table)[11])
{
	int	i;
	int	j;
	int	**syn_tb;

	syn_tb = strict_malloc(sizeof(int *), 11);
	i = -1;
	while (++i < 11)
	{
		syn_tb[i] = strict_malloc(sizeof(int), 11);
		j = -1;
		while (++j < 11)
			syn_tb[i][j] = (int) table[i][j];
	}
	return (syn_tb);
}

int	**get_syntax_table(void)
{
	static const char	table[11][11] = {\
									{1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0}, \
									{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, \
									{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, \
									{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, \
									{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, \
									{1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0}, \
									{1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0}, \
									{1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0}, \
									{1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0}, \
									{0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0}, \
									{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, \
									};

	return (copy_table(table));
}

void	free_syntax_table(int **syn_tb)
{
	int	i;

	i = 0;
	while (i < 11)
		free(syn_tb[i++]);
	free(syn_tb);
}
