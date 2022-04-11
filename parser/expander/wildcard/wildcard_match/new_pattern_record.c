/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_pattern_record.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 02:25:22 by mypark            #+#    #+#             */
/*   Updated: 2022/04/12 02:27:28 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wildcard_match.h"
#include "strict.h"

t_pattern_record	*new_pattern_record(int wi, int pi)
{
	t_pattern_record *new_rec;

	new_rec = strict_malloc(sizeof(t_pattern_record), 1);
	new_rec->index_word = wi;
	new_rec->index_pattern = pi;
	return (new_rec);
}
