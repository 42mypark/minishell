/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_matcher.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 23:35:11 by mypark            #+#    #+#             */
/*   Updated: 2022/04/10 21:24:43 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WILDCARD_MATCHER_H
# define WILDCARD_MATCHER_H
# include "parse_tree.h"

typedef enum e_wildcard_matcher_state
{
	WM_WILDCARD,
	WM_COMPARE,
	WM_REJECT
}			t_wildcard_matcher_state;

typedef struct s_wildcard_matcher
{
	t_wildcard_matcher_state	state;
	char						*pattern_raw;
	char						**patterns;
	int							pattern_index;
	char						*(*get_curr_pattern)(\
									struct s_wildcard_matcher *\
								);
	void						(*actions[2])(\
									struct s_wildcard_matcher *, \
									char *, int*\
								);
}				t_wildcard_matcher;

void	wildcard_matcher_compare(\
	t_wildcard_matcher *matcher, \
	char *word, \
	int *wi\
);
void	wildcard_matcher_wildcard(\
	t_wildcard_matcher *matcher, \
	char *word, \
	int *wi\
);

#endif
