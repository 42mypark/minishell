/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_exe_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 20:35:06 by mypark            #+#    #+#             */
/*   Updated: 2022/04/22 07:12:04 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	print_pid(void *content)
{
	int	*p;

	p = (int *)content;
	printf("\t %5d \n", p[0]);
}

void	print_pipe(void *content)
{
	int	*p;

	p = (int *)content;
	printf("\t ( re : %02d, we : %02d )\n", p[0], p[1]);
}

void	print_exe_info(t_exe_info *info)
{
	if (info->pids)
	{
		printf("pids : \n");
		ft_lstiter(info->pids, print_pid);
	}
	else
		printf("pids : NULL\n");
	if (info->pipes)
	{
		printf("pipes : \n");
		ft_lstiter(info->pipes, print_pipe);
	}
	else
		printf("pipes : NULL\n");
	if (info->exits)
	{
		printf("exits : \n");
		ft_lstiter(info->exits, print_pid);
	}
	else
		printf("exits : NULL\n");
}
