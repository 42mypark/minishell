/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_tree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 01:28:21 by mypark            #+#    #+#             */
/*   Updated: 2022/03/30 20:27:51 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	EXE_TREE_H
# define EXE_TREE_H

enum e_exetree_node
{
	EXE_ERROR,
	EXE_REDIR,
	EXE_PIPE,
	EXE_AND,
	EXE_OR
};

typedef struct s_err_info
{
	int			exit_status;
	const char	*msg;
}				t_err_info;

typedef struct s_cmd_info
{
	char	*cmd;
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

t_exetree_node	*new_exetree_node(enum e_exetree_node type, int infd, int outfd);
void			free_exetree_node(t_exetree_node *node);
t_err_info		*new_err_info(const char *msg, int exit_status);
void			free_err_info(t_err_info *info);
t_cmd_info		*new_cmd_info(char *cmd, char **args, char **envp);
void			free_cmd_info(t_cmd_info *info);

#endif
