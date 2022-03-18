/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 12:03:23 by mypark            #+#    #+#             */
/*   Updated: 2022/03/17 02:13:20 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_first_of_word(char const *init, const char *s, char c)
{
	char	curr;
	char	prev;

	if (s == init)
	{
		if (*s != c)
			return (1);
		else
			return (0);
	}
	curr = *s;
	prev = *(s - 1);
	if (curr != c && prev == c)
		return (1);
	return (0);
}

static int	is_last_of_word(const char *s, char c)
{
	char	curr;
	char	next;

	curr = *s;
	next = *(s + 1);
	if (curr != c && (next == c || next == '\0'))
		return (1);
	return (0);
}

static char	**word_alloc(char const *s, char c)
{
	char		**words;
	int			wc;

	wc = 0;
	while (*s)
	{
		if (is_last_of_word(s, c))
			wc++;
		s++;
	}
	words = malloc(sizeof(char *) * (wc + 1));
	if (words == NULL)
		return (NULL);
	words[wc] = NULL;
	return (words);
}

static void	*_free_words(char **words, int wc)
{
	while (wc-- > 0)
	{
		free(words[wc]);
	}
	free(words);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char		**words;
	int			wc;
	int			start;
	int			i;

	words = word_alloc(s, c);
	if (words == NULL)
		return (NULL);
	i = 0;
	wc = 0;
	while (s[i])
	{
		if (is_first_of_word(s, s + i, c))
			start = i;
		if (is_last_of_word(s + i, c))
		{
			words[wc] = malloc(sizeof(char) * ((i - start + 1) + 1));
			if (words[wc] == NULL)
				return (_free_words(words, wc));
			ft_strlcpy(words[wc++], s + start, (i - start + 1) + 1);
		}
		i++;
	}
	return (words);
}
