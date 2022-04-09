/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 02:31:21 by mypark            #+#    #+#             */
/*   Updated: 2022/04/09 18:00:56 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "strict.h"
#include "info.h"
#include <stdio.h>

void	close_pipes(t_exe_info *info)
{
	int		*p;
	t_list	*curr;

	curr = info->pipes;
	while (curr)
	{
		p = (int *)curr->content;
		if (p[0] != -1)
			strict_close(p[0]);
		if (p[1] != -1)
			strict_close(p[1]);
		curr = curr->next;
	}
	free_exe_info_pipes(info);
}
