/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 02:14:16 by mypark            #+#    #+#             */
/*   Updated: 2022/04/09 19:22:30 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	is_builtin(char *cmd)
{
	static char	*builtins[] = {\
							"echo", \
							"cd", \
							"pwd", \
							"export", \
							"unset", \
							"env", \
							"exit", \
							0};
	int			i;

	i = 0;
	while (builtins[i])
	{
		if (is_same(builtins[i], cmd))
			return (1);
		i++;
	}
	return (0);
}
