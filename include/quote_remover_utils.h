/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_remover_utils.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 23:35:11 by mypark            #+#    #+#             */
/*   Updated: 2022/03/26 16:59:02 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_EXPANDER_UTILS_H
# define ENV_EXPANDER_UTILS_H
# include "utils.h"
# include "token.h"
# include "parse_tree.h"

typedef enum e_quote_remover_state
{
	Q_CHARS,
	Q_DOUBLE_QUOTE,
	Q_SINGLE_QUOTE
}			t_quote_remover_state;

t_quote_remover_state	quote_remover_chars(t_buffer *buf, char input);
t_quote_remover_state	quote_remover_double_quote(t_buffer *buf, char input);
t_quote_remover_state	quote_remover_single_quote(t_buffer *buf, char input);
void					expand_tour_tree(t_parsetree_node *node, t_tokens *(*todo)(t_token *, char **),char **envp);

#endif
