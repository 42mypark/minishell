/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_lst.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 01:36:51 by mypark            #+#    #+#             */
/*   Updated: 2022/03/15 03:28:28 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BI_LST_H
# define BI_LST_H

typedef struct s_bi_lst
{
	void			*content;
	struct s_bi_lst	*next;
	struct s_bi_lst	*prev;
}				t_bi_lst;

void		bi_lstadd_back(t_bi_lst **lst, t_bi_lst *new);
t_bi_lst	*bi_lstpop_front(t_bi_lst **lst);
void		bi_lstdelone(t_bi_lst *lst, void (*del)(void *));
t_bi_lst	*bi_lstfind_forward(t_bi_lst *curr, void *target, int (*cmp)(void *, void *));
t_bi_lst	*bi_lstfind_backward(t_bi_lst *curr, void *target, int (*cmp)(void *, void *));
t_bi_lst	*bi_lstlast(t_bi_lst *lst);
t_bi_lst	*bi_lstnew(void *content);
int			bi_lstsize(t_bi_lst *lst);

#endif
