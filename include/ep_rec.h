/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ep_rec.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 23:35:11 by mypark            #+#    #+#             */
/*   Updated: 2022/03/26 20:02:10 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EP_REC_H
# define EP_REC_H
# include "libft.h"

typedef t_list	t_ep_rec;

typedef struct s_ep_range
{
	int	start;
	int	end;
}				t_ep_range;

t_ep_range	*new_ep_range(int s, int e);
void		free_ep_range(void *ep_range);
void		add_ep_rec_back(t_ep_rec **ep_rec, t_ep_range *content);
void		free_ep_rec(t_ep_rec **ep_rec);

#endif
