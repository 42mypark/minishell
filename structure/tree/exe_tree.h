/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_tree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 01:28:21 by mypark            #+#    #+#             */
/*   Updated: 2022/04/05 16:12:58 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	EXE_TREE_H
# define EXE_TREE_H
# include "info.h"

enum e_exetree_node
{
	EXE_ERROR,
	EXE_REDIR,
	EXE_PIPE,
	EXE_AND,
	EXE_OR
};

typedef struct s_exetree_node
{
	enum e_exetree_node		type;
	struct s_exetree_node	*parent;
	struct s_exetree_node	*left;
	struct s_exetree_node	*right;
	int						*fd;
	t_cmd_info				*cmd;
	t_err_info				*err;
}				t_exetree_node;

t_exetree_node	*new_exetree_node(t_exetree_node *parent, enum e_exetree_node type, int infd, int outfd);
void			free_exetree_node(t_exetree_node *node);
void			free_exetree(t_exetree_node *node);

#endif
