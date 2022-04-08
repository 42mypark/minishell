/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 13:23:58 by mypark            #+#    #+#             */
/*   Updated: 2022/04/08 16:21:23 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H
# include "libft.h"
# include "utils.h"

enum e_token
{
	TK_STR,
	TK_IRD,
	TK_ORD,
	TK_HRD,
	TK_ARD,
	TK_PIPE,
	TK_AND,
	TK_OR,
	TK_LPT,
	TK_RPT,
	TK_INVALID,
	TK_EXPANDED_STR,
	TK_QUOTED_STR
};

typedef struct s_token
{
	enum e_token	type;
	char			*content;
	t_list			*expansion_record;
}				t_token;

typedef t_deque			t_tokens;
typedef t_deque_node	t_tokens_node;

void		free_token(void *token);
void		free_tokens(t_tokens *tks);
int			token_type_cmp(void *a, void *b);
t_token		*new_token(enum e_token type, char *content);
t_tokens	*new_tokens(void);
t_tokens	*cut_tokens_back(t_tokens *tks, t_tokens_node *curr);
t_tokens	*cut_tokens_front(t_tokens *tks, t_tokens_node *curr);
t_tokens	*merge_tokens(t_tokens *tks1, t_tokens *tks2);
void		issue_token(t_tokens *tks, t_buffer *buf);
char		**tokens_to_splited(t_tokens *tks);
int			count_token(t_tokens *tks);

#endif
