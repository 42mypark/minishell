/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_expander_utils.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 23:35:11 by mypark            #+#    #+#             */
/*   Updated: 2022/03/27 15:05:07 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WILDCARD_EXPANDER_UTILS_H
# define WILDCARD_EXPANDER_UTILS_H
# include "parse_tree.h"

typedef enum e_wildcard_epdr_state
{
	A_WILDCARD,
	A_COMPARE,
	A_REJECT
}			t_wildcard_epdr_state;

t_wildcard_epdr_state	wildcard_epdr_compare(char **splited_format, \
											char *file, int *wc, int *fi);
t_wildcard_epdr_state	wildcard_epdr_wildcard(char **splited_format, \
											char *file, int *wc, int *fi);
int						wildcard_check_format(char *file, char *format);
void					expand_tour_tree(t_parsetree_node *node, \
										t_tokens *(*todo)(t_token *, char **), \
										char **envp);
char					**dup_filenames(void);

#endif
