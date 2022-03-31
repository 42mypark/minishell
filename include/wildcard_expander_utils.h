/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_expander_utils.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 23:35:11 by mypark            #+#    #+#             */
/*   Updated: 2022/03/31 21:17:01 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WILDCARD_EXPANDER_UTILS_H
# define WILDCARD_EXPANDER_UTILS_H
# include "parse_tree.h"

typedef enum e_wildcard_matcher_state
{
	WM_WILDCARD,
	WM_COMPARE,
	WM_REJECT
}			t_wildcard_matcher_state;

typedef enum e_wildcard_spliter_state
{
	WS_DOUBLE_QUOTE,
	WS_SINGLE_QUOTE,
	WS_CHARS
}			t_wildcard_spliter_state;

void						expand_tour_tree(\
	t_parsetree_node *node, \
	char **envp);
int							wildcard_check_format(\
	char *file, \
	t_token *tk, \
	char **formats);
char						**wildcard_split(t_token *tk);
char						**dup_filenames(void);
t_wildcard_matcher_state	wildcard_matcher_compare(\
	char **splited_format, \
	char *file, \
	int *wc, \
	int *fi);
t_wildcard_matcher_state	wildcard_matcher_wildcard(\
	char **splited_format, \
	char *file, \
	int *wc, \
	int *fi);
t_wildcard_spliter_state	wildcard_spliter_double_quote(\
	t_buffer *buf, \
	t_token *origin, \
	int i);
t_wildcard_spliter_state	wildcard_spliter_single_quote(\
	t_buffer *buf, \
	t_token *origin, \
	int i);
t_wildcard_spliter_state	wildcard_spliter_chars(\
	t_tokens *tks, \
	t_buffer *buf, \
	t_token *origin, \
	int i);
#endif
