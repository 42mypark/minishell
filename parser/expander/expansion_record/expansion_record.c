/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_record.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 20:01:45 by mypark            #+#    #+#             */
/*   Updated: 2022/04/01 15:04:58 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion_record.h"
#include "libft.h"

void	expansion_record_add_back(\
	t_expansion_record **expansion_record, \
	t_expansion_range *content\
)
{
	ft_lstadd_back(expansion_record, ft_lstnew(content));
}

void	free_expansion_record(t_expansion_record *expansion_record)
{
	ft_lstclear(&expansion_record, free_expansion_range);
}

t_expansion_record	*dup_expansion_record(t_expansion_record *expansion_record)
{
	return (ft_lstdup(expansion_record, dup_expansion_range));
}
