/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_match.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 23:35:11 by mypark            #+#    #+#             */
/*   Updated: 2022/04/22 08:08:00 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WILDCARD_MATCH_H
# define WILDCARD_MATCH_H
# include "libft.h"
# include "strict.h"

typedef struct s_pattern_record
{
	int	index_word;
	int	index_pattern;
}				t_pattern_record;

typedef struct s_wildcard_info
{
	char	**patterns;
	int		pattern_counts;
	int		last_wildcard;
	int		first_wildcard;
	t_stack	*stack;
}				t_wildcard_info;

t_pattern_record	*new_pattern_record(int wi, int pi);

#endif
