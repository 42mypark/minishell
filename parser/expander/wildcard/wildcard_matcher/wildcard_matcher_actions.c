/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_matcher_actions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 00:18:12 by mypark            #+#    #+#             */
/*   Updated: 2022/04/11 20:47:29 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wildcard_matcher.h"
#include "utils.h"

void	wildcard_matcher_compare(\
	t_wildcard_matcher *matcher, \
	char *word, \
	int *wi
)
{
	int		len;
	char	*curr_pattern;
	char	escape_char;
	int		i;

	curr_pattern = matcher->get_curr_pattern(matcher);
	escape_char = curr_pattern[0];
	len = ft_strlen(curr_pattern);
	i = *wi;
	while(word[i])
	{
		if (word[i] == escape_char \
		&& ft_strncmp(word + i, curr_pattern, len) == 0)
		{
			(*wi) += (len + i);
			matcher->pattern_index++;
			matcher->state = WM_WILDCARD;
			return ;
		}
		i++;
	}
	matcher->state = WM_REJECT;
	// else
	// 	matcher->state = WM_REJECT;
}

void	wildcard_matcher_wildcard(\
	t_wildcard_matcher *matcher, \
	char *word, \
	int *wi
)
{
	char	escape_char;
	char	*curr_pattern;

	curr_pattern = matcher->get_curr_pattern(matcher);
	escape_char = curr_pattern[0];
	if (word[*wi] == escape_char)
		matcher->state = WM_COMPARE;
	else
	{
		(*wi)++;
		matcher->state = WM_WILDCARD;
	}
}
