/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tree.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 13:23:58 by mypark            #+#    #+#             */
/*   Updated: 2022/03/31 01:55:25 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_TREE_H
# define PARSE_TREE_H
# include "token.h"

enum e_parsetree_node
{
	TOKENS = 1,
	NODE_AND = 1 << 1,
	NODE_OR = 1 << 2,
	NODE_PIPE = 1 << 3,
	NODE_IRD = 1 << 4,
	NODE_ORD = 1 << 5,
	NODE_ARD = 1 << 6,
	NODE_HRD = 1 << 7,
};

typedef struct s_parsetree_node
{
	enum e_parsetree_node	type;
	t_tokens				*tokens;
	struct s_parsetree_node	*parent;
	struct s_parsetree_node	*left;
	struct s_parsetree_node	*right;
}				t_parsetree_node;

t_parsetree_node		*new_parsetree_node(t_tokens *tks, \
											t_parsetree_node *parent);
void					free_parsetree_node(t_parsetree_node *node);
enum e_parsetree_node	to_enum_parsetree_node(enum e_token tk_type);
void					free_parsetree(t_parsetree_node *node);

#endif
