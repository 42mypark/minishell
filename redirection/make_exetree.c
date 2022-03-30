/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_exetree_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:40:03 by mypark            #+#    #+#             */
/*   Updated: 2022/03/31 00:15:43 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe_tree.h"
#include "parse_tree.h"
#include "utils.h"
#include "test.h"
#include <fcntl.h>
#include "redirection_utils.h"
#include "info.h"

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

int	is_ambiguous(t_parsetree_node *p_nd)
{
	if (count_token(p_nd->tokens) != 1)
		return (1);
	return (0);
}

static int	meet_not_redir(t_parsetree_node *p_nd, t_exetree_node *e_nd, t_exe_info *info)
{
	if (p_nd->type == TOKENS && make_cmd(p_nd, e_nd, info))
		return (1) ;
	if (p_nd->type & (NODE_OR | NODE_AND | NODE_PIPE))
	{
		e_nd->left = make_exetree_node(p_nd->left, e_nd->infd, e_nd->outfd, info);
		return (1);
	}
	return (0);
}


static void	make_exe_redir(t_parsetree_node *p_nd, t_exetree_node *e_nd, t_exe_info *info)
{
	while (p_nd)
	{
		if (meet_not_redir(p_nd, e_nd, info))
			break;
		if (is_ambiguous(p_nd->right))
		{
			e_nd->type = EXE_ERROR;
			e_nd->err = new_err_info("minishell : ambiguous redirect", 1);
			break ;
		}
		if (meet_redir(p_nd, e_nd, info) == 0)
			break;
		p_nd = p_nd->left;
	}
}

t_exetree_node	*make_exetree_node(t_parsetree_node *p_nd, int infd, int outfd, t_exe_info *info)
{
	t_exetree_node	*e_nd;
	int				p[2];

	e_nd = new_exetree_node(to_enum_exetree_node(p_nd->type), infd, outfd);
	if (p_nd->type == NODE_PIPE)
	{
		pipe(p);
		insert_new_pipe(info, p);
		printf("pipe re : %d, we : %d\n", p[0], p[1]);
		e_nd->left = make_exetree_node(p_nd->left, e_nd->infd, p[1], info);
		e_nd->right = make_exetree_node(p_nd->right, p[0], e_nd->outfd, info);
	}
	else if (p_nd->type & (NODE_AND | NODE_OR))
	{
		e_nd->left = make_exetree_node(p_nd->left, e_nd->infd, e_nd->outfd, info);
		e_nd->right = make_exetree_node(p_nd->right, e_nd->infd, e_nd->outfd, info);
	}
	else if (p_nd->type == TOKENS)
		make_cmd(p_nd, e_nd, info);
	else if (p_nd->type & (NODE_IRD | NODE_ORD | NODE_ARD | NODE_HRD))
		make_exe_redir(p_nd, e_nd, info);
	return (e_nd);
}

t_exetree_node	*make_exetree(t_parsetree_node *p_nd, t_exe_info *info)
{
	return (make_exetree_node(p_nd, 0, 1, info));
}

