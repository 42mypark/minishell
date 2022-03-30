/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_to_exe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:40:03 by mypark            #+#    #+#             */
/*   Updated: 2022/03/30 22:28:41 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe_tree.h"
#include "parse_tree.h"
#include "utils.h"
#include "test.h"
#include <fcntl.h>

t_exetree_node	*parse_to_exe(t_parsetree_node *p_nd, int infd, int outfd, char **envp);

static enum e_exetree_node	to_enum_exetree_node(enum e_parsetree_node type)
{
	if (type == NODE_AND)
		return (EXE_AND);
	if (type == NODE_OR)
		return (EXE_OR);
	if (type == NODE_PIPE)
		return (EXE_PIPE);
	return (EXE_REDIR);
}

static char	*can_access(char *cmd, char **paths)
{
	int	i;

	if (access((const char *)cmd, X_OK) == 0)
		return (cmd);
	i = 0;
	while (paths[i])
	{
		paths[i] = ft_strappend(paths[i], "/");
		paths[i] = ft_strappend(paths[i], cmd);
		if (access((const char *)paths[i], X_OK) == 0)
			return (paths[i]);
		i++;
	}
	return (0);
}

int	make_cmd(t_parsetree_node *p_nd, t_exetree_node *e_nd, char **envp)
{
	char	**args;
	char	**paths;
	char	*env_path;
	char	*cmd;

	args = tokens_to_splited(p_nd->tokens);
	env_path = dupenv("PATH", envp);
	paths = ft_split(env_path, ':');
	cmd = can_access(args[0], paths);
	if (cmd != NULL)
		e_nd->cmd = new_cmd_info(ft_strdup(cmd), args, envp);
	else
	{
		e_nd->type = EXE_ERROR;
		e_nd->err = new_err_info("minishell : command not found", 127);
	}
	ft_free_splited(paths);
	free(env_path);
	return (1);
}

static int	register_new_fd(t_exetree_node *e_nd, int *dst_fd, char *file_name, int flag)
{
	int	fd;
	
	if (*dst_fd != 0 && *dst_fd != 1)
		close(*dst_fd);
	fd = open(file_name, flag, 644);
	printf("fd : %d \t filename : %s \n", fd, file_name);
	if (fd == -1)
	{
		e_nd->type = EXE_ERROR;
		e_nd->err = new_err_info("minishell : No such file or directory", 1);
		return (0);
	}
	*dst_fd = fd;
	return (1);
}

int	to_open_flag(enum e_parsetree_node type)
{
	if (type == NODE_ARD)
		return (O_APPEND | O_CREAT);
	if (type == NODE_ORD)
		return (O_WRONLY | O_CREAT | O_TRUNC);
	return (O_RDONLY);
}

int	is_ambiguous(t_parsetree_node *p_nd)
{
	if (count_token(p_nd->tokens) != 1)
		return (1);
	return (0);
}

int	not_redir(t_parsetree_node *p_nd, t_exetree_node *e_nd, char **envp)
{
	if (p_nd->type == TOKENS && make_cmd(p_nd, e_nd, envp))
		return (0) ;
	if (p_nd->type & (NODE_OR | NODE_AND | NODE_PIPE))
	{
		e_nd->left = parse_to_exe(p_nd->left, e_nd->infd, e_nd->outfd, envp);
		return (0);
	}
	return (1);
}

void	make_exe_redir(t_parsetree_node *p_nd, t_exetree_node *e_nd, char **envp)
{
	t_token *tk;

	while (p_nd)
	{
		if (not_redir(p_nd, e_nd, envp) == 0)
			break;
		if (is_ambiguous(p_nd->right))
		{
			e_nd->type = EXE_ERROR;
			e_nd->err = new_err_info("minishell : ambiguous redirect", 1);
			break ;
		}
		tk = p_nd->right->tokens->head->content;
		if (p_nd->type == NODE_IRD && register_new_fd(e_nd, &e_nd->infd, tk->content, to_open_flag(p_nd->type)) == 0)
			break ;
		if (p_nd->type & (NODE_ORD | NODE_ARD) &&  register_new_fd(e_nd, &e_nd->outfd, tk->content, to_open_flag(p_nd->type)) == 0)
			break ;
		if (p_nd->type == NODE_HRD)
		{
			tk = p_nd->right->tokens->head->content;
			if (tk->type == QUOTED_STR)
			{
			}
			else
			{
			}
		}
		p_nd = p_nd->left;
	}
}

t_exetree_node	*parse_to_exe(t_parsetree_node *p_nd, int infd, int outfd, char **envp)
{
	t_exetree_node	*e_nd;
	int				p[2];
	
	e_nd = new_exetree_node(to_enum_exetree_node(p_nd->type), infd, outfd);
	if (p_nd->type == NODE_PIPE)
	{
		//record pipe ?
		pipe(p);
		printf("pipe re : %d, we : %d\n", p[0], p[1]);
		e_nd->left = parse_to_exe(p_nd->left, e_nd->infd, p[1], envp);
		e_nd->right = parse_to_exe(p_nd->right, p[0], e_nd->outfd, envp);
	}
	else if (p_nd->type & (NODE_AND | NODE_OR))
	{
		e_nd->left = parse_to_exe(p_nd->left, e_nd->infd, e_nd->outfd, envp);
		e_nd->right = parse_to_exe(p_nd->right, e_nd->infd, e_nd->outfd, envp);
	}
	else if (p_nd->type == TOKENS)
		make_cmd(p_nd, e_nd, envp);
	else if (p_nd->type & (NODE_IRD | NODE_ORD | NODE_ARD | NODE_HRD))
		make_exe_redir(p_nd, e_nd, envp);
	return (e_nd);
}