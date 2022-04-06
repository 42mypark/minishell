/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 01:28:21 by mypark            #+#    #+#             */
/*   Updated: 2022/04/06 17:31:02 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	EXECUTOR_H
# define EXECUTOR_H
# include "exe_tree.h"
# include "info.h"

int		execute_node(t_exetree_node *exe_node, int *parent_fd, t_exe_info *info);
void	executor(t_exetree_node *exe_node, t_exe_info *info);
int		calc_exit_status(int ws);
int		exe_and(t_exetree_node *exe_node, int *parent_fd, t_exe_info *info);
int		exe_or(t_exetree_node *exe_node, int *parent_fd, t_exe_info *info);
int		exe_pipe(t_exetree_node *exe_node, int *parent_fd, t_exe_info *info);
int		exe_redir(t_exetree_node *exe_node, int *parent_fd, t_exe_info *info);
int		exe_bool_child(t_exetree_node *child, int *fd, t_exe_info *info);
void	close_fd(t_exetree_node *exe_node, t_exe_info *info);
void	close_pipes(t_exe_info *info);
void	close_pipe_oneside(t_exetree_node *parent, t_exetree_node *exe_node, t_exe_info *info);
void	set_exe_node_fd(t_exetree_node *exe_node, int *parent_fd);
void	restore_inout_fd(t_exetree_node *e_node);

#endif
