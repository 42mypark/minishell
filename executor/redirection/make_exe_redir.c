/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 00:12:54 by mypark            #+#    #+#             */
/*   Updated: 2022/04/08 17:16:14 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe_tree.h"
#include "parse_tree.h"
#include "token.h"
#include "strict.h"
#include "heredoc.h"
#include <fcntl.h>
#include <sys/wait.h>

static int	to_open_flag(enum e_parsetree_node type)
{
	if (type == NODE_ARD)
		return (O_APPEND | O_CREAT);
	if (type == NODE_ORD)
		return (O_WRONLY | O_CREAT | O_TRUNC);
	return (O_RDONLY);
}

static int	register_fd(t_exetree_node *e_nd, int *dst_fd, char *file_name, int flag)
{
	int	fd;

	if (*dst_fd != 0 && *dst_fd != 1)
		strict_close(*dst_fd);
	fd = strict_open(file_name, flag, 0644);
	if (fd == -1)
	{
		e_nd->type = EXE_ERROR;
		e_nd->err = new_err_info("minishell : No such file or directory", 1);
		return (0);
	}
	*dst_fd = fd;
	return (1);
}

static int	meet_redir(t_parsetree_node *p_nd, t_exetree_node *e_nd, t_exe_info *info)
{
	t_token	*tk;
	int		flag;

	tk = p_nd->right->tokens->head->content;
	flag = to_open_flag(p_nd->type);
	if (p_nd->type & (NODE_ORD | NODE_ARD) \
	&& register_fd(e_nd, &e_nd->fd[1], tk->content, flag) == 0)
		return (0);
	else if (p_nd->type == NODE_IRD \
	&& register_fd(e_nd, &e_nd->fd[0], tk->content, flag) == 0)
		return (0);
	else if (p_nd->type == NODE_HRD)
		make_heredoc(e_nd, tk, info);
	return (1);
}

static int	meet_not_redir(t_parsetree_node *p_nd, t_exetree_node *e_nd, t_exe_info *info)
{
	if (p_nd->type == TOKENS && make_cmd(p_nd, e_nd, info))
		return (1) ;
	if (p_nd->type & (NODE_OR | NODE_AND | NODE_PIPE))
	{
		e_nd->left = make_exetree_node(e_nd, p_nd, e_nd->fd, info);
		return (1);
	}
	return (0);
}

void	make_exe_redir(t_parsetree_node *p_nd, t_exetree_node *e_nd, t_exe_info *info)
{
	while (p_nd)
	{
		if (meet_not_redir(p_nd, e_nd, info))
			break;
		if (count_token(p_nd->right->tokens) != 1)
		{
			e_nd->type = EXE_ERROR;
			e_nd->err = new_err_info("minishell : ambiguous redirect", 1);
			break ;
		}
		if (meet_redir(p_nd, e_nd, info) == 0)
			break ;
		p_nd = p_nd->left;
	}
}
