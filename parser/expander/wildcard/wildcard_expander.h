/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_expander.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 23:35:11 by mypark            #+#    #+#             */
/*   Updated: 2022/04/05 13:15:46 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WILDCARD_EXPANDER_H
# define WILDCARD_EXPANDER_H
# include "token.h"
# include "utils.h"

char	**wildcard_split(t_token *tk);
int		wildcard_match(char *word, char *pattern_raw, char **patterns);
char	**dup_filenames(void);

#endif
