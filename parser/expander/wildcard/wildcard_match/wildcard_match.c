/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_match.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:38:09 by mypark            #+#    #+#             */
/*   Updated: 2022/04/12 03:41:58 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "strict.h"
#include "wildcard_match.h"
#include "constant.h"

int	first_pattern(t_wildcard_info *info, char *word)
{
	int					len;
	t_stack				*stack;
	t_pattern_record	*new_rec;

	stack = info->stack;
	if (info->first_wildcard)
	{
		new_rec = new_pattern_record(-1, 0);
		stack->push(stack, new_rec);
	}
	else
	{
		len = ft_strlen(info->patterns[0]);
		if (ft_strncmp(word, info->patterns[0], len) == 0)
		{
			new_rec = new_pattern_record(len - 1, 1);
			stack->push(stack, new_rec);
		}
		else
			return (0);
	}
	return (1);
}

static int	is_matched(t_wildcard_info *info, char last_char, int pattern_end)
{
	if (last_char == '\0' && pattern_end)
		return (1);
	if (last_char != '\0' && info->last_wildcard)
		return (1);
	return (0);
}

int	match_patterns(t_wildcard_info *info, t_pattern_record *curr, char *word)
{
	int		wi;
	int		pi;
	int		pattern_len;
	char	**patterns;
	t_stack	*stack;

	patterns = info->patterns;
	stack = info->stack;
	wi = curr->index_word;
	pi = curr->index_pattern;
	pattern_len = ft_strlen(patterns[pi]);
	while (word[++wi] && pi < info->pattern_counts)
	{
		if (word[wi] == patterns[pi][0] \
		&& ft_strncmp(word + wi, patterns[pi], pattern_len) == 0)
		{
			stack->push(stack, new_pattern_record(wi, pi));
			wi += (ft_strlen(patterns[pi]) - 1);
			pi++;
			pattern_len = ft_strlen(patterns[pi]);
		}
	}
	if (is_matched(info, word[wi], (pi == info->pattern_counts)))
		return (1);
	return (0);
}

void	init_wildcard_info(\
	t_wildcard_info *info, \
	char *pattern_raw, \
	char **patterns\
)
{
	int	last_index;

	info->patterns = patterns;
	info->pattern_counts = ft_wordcount(patterns);
	info->stack = new_stack();
	if (info->stack == FT_NULL)
		print_malloc_error();
	info->first_wildcard = (pattern_raw[0] == '*');
	last_index = ft_strlen(pattern_raw) - 1;
	info->last_wildcard = (pattern_raw[last_index] == '*');
}


int	wildcard_match(char *word, char *pattern_raw, char **patterns)
{
	t_wildcard_info		info;
	t_pattern_record	*curr;

	init_wildcard_info(&info, pattern_raw, patterns);
	if (first_pattern(&info, word) == 0)
	{
		free_stack(info.stack, free);
		return (0);
	}
	while (info.stack->top)
	{
		curr = info.stack->pop(info.stack);
		if (match_patterns(&info, curr, word))
		{
			free(curr);
			free_stack(info.stack, free);
			return (1);
		}
		free(curr);
	}
	free_stack(info.stack, free);
	return (0);
}
