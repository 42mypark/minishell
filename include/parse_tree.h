/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tree.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 13:23:58 by mypark            #+#    #+#             */
/*   Updated: 2022/03/18 19:13:14 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_TREE_H
# define PARSE_TREE_H
# include "token.h"

typedef struct s_pt_node
{
	int					parsed;
	t_tokens			*tokens;
	struct s_pt_node	*parent;
	struct s_pt_node	*left;
	struct s_pt_node	*right;
}				t_pt_node;

t_pt_node		*new_pt_node(t_tokens *tks, t_pt_node *parent);
int				parse_redir(t_pt_node *pt_node); // pass prth
int				parse_bool(t_pt_node *pt_node);
int				parse_pipe(t_pt_node *pt_node);
int				remove_prth(t_pt_node *pt_node);
t_tokens_node	*pass_prth(t_tokens_node *curr);

#endif
