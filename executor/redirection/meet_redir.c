/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meet_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 00:12:54 by mypark            #+#    #+#             */
/*   Updated: 2022/04/02 20:57:01 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe_tree.h"
#include "parse_tree.h"
#include "utils.h"
#include "test.h"
#include "strict.h"
#include <fcntl.h>
#include "redirection_utils.h"

static int	register_fd(t_exetree_node *e_nd, int *dst_fd, char *file_name, int flag)
{
	int	fd;

	if (*dst_fd != 0 && *dst_fd != 1)
		strict_close(*dst_fd);
	fd = open(file_name, flag, 0644);
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

static int	to_open_flag(enum e_parsetree_node type)
{
	if (type == NODE_ARD)
		return (O_APPEND | O_CREAT);
	if (type == NODE_ORD)
		return (O_WRONLY | O_CREAT | O_TRUNC);
	return (O_RDONLY);
}

int	meet_redir(t_parsetree_node *p_nd, t_exetree_node *e_nd, t_exe_info *info)
{
	t_token	*tk;
	int		flag;
	int		p[2];

	tk = p_nd->right->tokens->head->content;
	flag = to_open_flag(p_nd->type);
	if (p_nd->type & (NODE_ORD | NODE_ARD) \
	&& register_fd(e_nd, &e_nd->outfd, tk->content, flag) == 0)
		return (0);
	else if (p_nd->type == NODE_IRD \
	&& register_fd(e_nd, &e_nd->infd, tk->content, flag) == 0)
		return (0);
	else if (p_nd->type == NODE_HRD)
	{
		if (e_nd->infd != 0)
			strict_close(e_nd->infd);
		pipe(p);
		if (tk->type == QUOTED_STR)
			listen_heredoc_quoted(tk->content, p[1]);
		else
			listen_heredoc(tk->content, p[1], info->envp);
		e_nd->infd = p[0];
		p[1] = -1;
		insert_new_pipe(info, p);
	}
	return (1);
}