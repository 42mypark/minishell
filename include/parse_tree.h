/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tree.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 13:23:58 by mypark            #+#    #+#             */
/*   Updated: 2022/03/18 15:02:05 by mypark           ###   ########.fr       */
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

t_tokens		divide_tokens_pao();
t_tokens		divide_tokens_red();
void			merge_token();

#endif
