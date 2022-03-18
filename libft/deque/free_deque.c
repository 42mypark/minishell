/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_deque.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:44:00 by mypark            #+#    #+#             */
/*   Updated: 2022/03/18 15:44:46 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"
#include <stdlib.h>

void	free_deque(t_deque *dq, void (*del)(void *))
{
	cir_lstclear(&dq->head, del);
	free(dq);
}
