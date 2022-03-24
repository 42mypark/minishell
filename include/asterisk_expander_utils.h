/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asterisk_expander_utils.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 23:35:11 by mypark            #+#    #+#             */
/*   Updated: 2022/03/24 20:57:10 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASTERISK_EXPANDER_UTILS_H
# define ASTERISK_EXPANDER_UTILS_H
# include "parse_tree.h"

typedef enum e_asterisk_epdr_state
{
	A_ASTERISK,
	A_COMPARE,
	A_REJECT
}			t_asterisk_epdr_state;

t_asterisk_epdr_state	asterisk_epdr_compare(char **splited_format, char *file, int *wc, int *fi);
t_asterisk_epdr_state	asterisk_epdr_asterisk(char **splited_format, char *file, int *wc, int *fi);
int						asterisk_check_format(char *file, char *format);
void					expand_tour_tree(t_parsetree_node *node, void (*todo)(t_tokens *, char *, char **), char **envp);
char					**dup_filenames();

#endif
