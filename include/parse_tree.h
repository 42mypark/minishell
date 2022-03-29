/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tree.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 13:23:58 by mypark            #+#    #+#             */
/*   Updated: 2022/03/29 17:56:52 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_TREE_H
# define PARSE_TREE_H
# include "token.h"

enum e_parsetree_node
{
	TOKENS,
	NODE_AND,
	NODE_OR,
	NODE_PIPE,
	NODE_IRD,
	NODE_ORD,
	NODE_ARD,
	NODE_HRD,
};

typedef struct s_parsetree_node
{
	enum e_parsetree_node	type;
	int						parsed;
	int						executed;
	t_tokens				*tokens;
	struct s_parsetree_node	*parent;
	struct s_parsetree_node	*left;
	struct s_parsetree_node	*right;
}				t_parsetree_node;

t_parsetree_node		*new_parsetree_node(t_tokens *tks, \
											t_parsetree_node *parent);
void					free_parsetree_node(t_parsetree_node *node);
enum e_parsetree_node	to_enum_parsetree_node(enum e_token tk_type);

#endif
