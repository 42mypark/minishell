/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 23:35:11 by mypark            #+#    #+#             */
/*   Updated: 2022/04/22 08:31:57 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

char	*dupenv(char *target, char **envp);
int		is_blank(char c);
int		is_bool(char c);
int		is_meta(char c);
int		is_parenthesis(char c);
int		is_redir(char c);
int		is_same(char *s1, char *s2);
int		set_state(int *old_state, int new_state);

#endif
