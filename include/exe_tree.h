/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_tree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 01:28:21 by mypark            #+#    #+#             */
/*   Updated: 2022/03/30 01:56:21 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	EXE_TREE_H
# define EXE_TREE_H

enum e_exetree_node
{
	ERROR,
	EXE_CMD,
	EXE_REDIR,
	EXE_PIPE,
	EXE_AND,
	EXE_OR
};

typedef struct s_err_info
{
	int		exit_status;
	char	*msg;
}				t_err_info;

typedef struct s_cmd_info
{
	char	**args;
	char	**envp;
}				t_cmd_info;

typedef struct s_exetree_node
{
	enum e_exetree_node		type;
	struct s_exetree_node	*left;
	struct s_exetree_node	*right;
	int						infd;
	int						outfd;
	t_cmd_info				*cmd;
	t_err_info				*err;
}				t_exetree_node;

#endif
