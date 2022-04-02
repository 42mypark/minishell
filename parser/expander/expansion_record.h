/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_record.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 23:35:11 by mypark            #+#    #+#             */
/*   Updated: 2022/03/26 21:21:02 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSION_RECORD_H
# define EXPANSION_RECORD_H
# include "libft.h"

typedef t_list	t_expansion_record;

typedef struct s_expansion_range
{
	int	start;
	int	end;
}				t_expansion_range;

t_expansion_range	*new_expansion_range(int s, int e);
void				free_expansion_range(void *expansion_range);
void				*dup_expansion_range(void *content);
void				free_expansion_record(t_expansion_record *expansion_record);
t_expansion_record	*dup_expansion_record(t_expansion_record *expansion_record);
void				expansion_record_add_back(t_expansion_record **expansion_record, t_expansion_range *content);

#endif
