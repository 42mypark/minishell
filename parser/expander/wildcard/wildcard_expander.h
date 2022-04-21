/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_expander.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 23:35:11 by mypark            #+#    #+#             */
/*   Updated: 2022/04/22 08:12:38 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WILDCARD_EXPANDER_H
# define WILDCARD_EXPANDER_H
# include "token.h"
# include "buffer.h"
# include "expansion_record.h"

char	**wildcard_split(t_token *tk);
int		wildcard_match(char *word, char *pattern_raw, char **patterns);
char	**dup_filenames(void);

#endif
