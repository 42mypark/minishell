/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 13:23:58 by mypark            #+#    #+#             */
/*   Updated: 2022/03/18 15:57:17 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H
# include "libft.h"

enum e_token
{
	STR,
	IRD,
	ORD,
	HRD,
	ARD,
	PIPE,
	AND,
	OR,
	LPT,
	RPT
};

typedef struct s_token
{
	enum e_token	type;
	char			*content;
}				t_token;

typedef t_deque t_tokens;

void		free_token(void *token);
void		free_tokens(t_tokens *tks);
t_token		*new_token(enum e_token type, char *content);
t_tokens	*new_tokens();

#endif
