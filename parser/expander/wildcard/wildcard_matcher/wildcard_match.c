/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_match.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:38:09 by mypark            #+#    #+#             */
/*   Updated: 2022/04/11 20:49:13 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "wildcard_matcher.h"

char	*get_curr_pattern(t_wildcard_matcher *matcher)
{
	return (matcher->patterns[matcher->pattern_index]);
}

static void	init_wildcard_matcher(\
	t_wildcard_matcher *matcher, \
	char *pattern_raw, \
	char **patterns\
)
{
	int	last_char;
	
	matcher->first_wildcard = (pattern_raw[0] == '*');
	last_char = ft_strlen(matcher->pattern_raw) - 1;
	matcher->last_wildcard = (pattern_raw[last_char] == '*');
	if (matcher->first_wildcard)
		matcher->state = WM_WILDCARD;
	else
		matcher->state = WM_COMPARE;
	matcher->actions[0] = wildcard_matcher_wildcard;
	matcher->actions[1] = wildcard_matcher_compare;
	matcher->pattern_index = 0;
	matcher->pattern_raw = pattern_raw;
	matcher->patterns = patterns;
	matcher->get_curr_pattern = get_curr_pattern;
}

static int	is_success(t_wildcard_matcher *matcher, char *word, int wi)
{
	if (matcher->get_curr_pattern(matcher) != NULL)
		return (0);
	if (matcher->last_wildcard && wi != (int)ft_strlen(word))
		return (0);
	return (1);
}

int	wildcard_match(char *word, char *pattern_raw, char **patterns)
{
	int					wi;
	t_wildcard_matcher	matcher;

	init_wildcard_matcher(&matcher, pattern_raw, patterns);
	wi = 0;
	while (word[wi] && matcher.get_curr_pattern(&matcher))
	{
		matcher.actions[matcher.state](&matcher, word, &wi);
		if (matcher.state == WM_REJECT)
			return (0);
	}
	if (!is_success(&matcher, word, wi))
		return (0);
	return (1);
}
