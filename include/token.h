/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 13:23:58 by mypark            #+#    #+#             */
/*   Updated: 2022/03/18 17:50:39 by mypark           ###   ########.fr       */
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

typedef t_deque			t_tokens;
typedef t_deque_node	t_tokens_node;

void		free_token(void *token);
void		free_tokens(t_tokens *tks);
t_token		*new_token(enum e_token type, char *content);
t_tokens	*new_tokens();
int			token_type_cmp(void *a, void *b);
t_tokens	*cut_tokens_backward(t_tokens *tks, t_tokens_node *curr);
t_tokens	*cut_tokens_forward(t_tokens *tks, t_tokens_node *curr);

#endif
