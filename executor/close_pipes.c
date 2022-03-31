/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 02:31:21 by mypark            #+#    #+#             */
/*   Updated: 2022/04/01 02:31:57 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "strict.h"

void	close_pipes(t_list *pipes)
{
	int	*p;
	while (pipes)
	{
		p = (int *)pipes->content;
		strict_close(p[0]);
		strict_close(p[1]);
		pipes = pipes->next;
	}
}
