/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:06:06 by mypark            #+#    #+#             */
/*   Updated: 2022/03/28 22:25:52 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "libft.h"
#include "ep_rec.h"
#include "test.h"

static int	is_first_of_format(char const *init, const char *s)
{
	char	curr;
	char	prev;

	if (s == init)
	{
		if (*s != '*')
			return (1);
		else
			return (0);
	}
	curr = *s;
	prev = *(s - 1);
	if (curr != '*' && prev == '*')
		return (1);
	return (0);
}

static int	is_last_of_format(const char *s)
{
	char	curr;
	char	next;

	curr = *s;
	next = *(s + 1);
	if (curr != '*' && (next == '*' || next == '\0'))
		return (1);
	return (0);
}

static int	is_outer_double_quote(t_token *tk, int i)
{
	t_ep_range	*range;
	t_ep_rec	*curr;

	curr = tk->ep_rec;
	while(curr)
	{
		range = curr->content;
		if (i >= range->start && i < range->end)
			return (0);
		curr = curr->next;
	}
	return (1);
}

static void	*_free_wilds(char **formats, int wc)
{
	while (wc-- > 0)
	{
		free(formats[wc]);
	}
	free(formats);
	return (NULL);
}

static int	jump_quote(t_token *tk, int i)
{
	char	*str;

	str = tk->content;
	i++;
	while(str[i])
	{
		if (str[i] == '\"' && is_outer_double_quote(tk, i))
			return (i);
		i++;
	}
	return (i);
}

static char	**formats_alloc(t_token *tk)
{
	char	**formats;
	char	*str;
	int		wc;
	int		dq;
	int		i;

	wc = 0;
	dq = 0;
	i = 0;
	str = tk->content;
	while (str[i])
	{
		if (str[i] == '\"' && is_outer_double_quote(tk, i))
			i = jump_quote(tk, i);
		else if (is_last_of_format(str + i))
			wc++;
		i++;
	}
	formats = malloc(sizeof(char *) * (wc + 1));
	if (formats == NULL)
		return (NULL);
	formats[wc] = NULL;
	return (formats);
}

char	**wildcard_split(t_token *tk)
{
	char	**formats;
	int		wc;
	int		start;
	int		i;
	char	*str;

	formats = formats_alloc(tk);
	if (formats == NULL)
		return (NULL);
	i = 0;
	wc = 0;
	str = tk->content;
	while (str[i])
	{
		if (str[i] == '\"' && is_outer_double_quote(tk, i))
			i = jump_quote(tk, i);
		else
		{
			if (is_first_of_format(str, str + i))
				start = i;
			if (is_last_of_format(str + i))
			{
				formats[wc] = malloc(sizeof(char) * ((i - start + 1) + 1));
				if (formats[wc] == NULL)
					return (_free_wilds(formats, wc));
				ft_strlcpy(formats[wc++], str + start, (i - start + 1) + 1);
			}
		}
		i++;
	}
	return (formats);
}
