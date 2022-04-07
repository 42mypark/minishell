/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 01:28:21 by mypark            #+#    #+#             */
/*   Updated: 2022/04/08 04:47:18 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	EXECUTOR_H
# define EXECUTOR_H
# include "exe_tree.h"
# include "info.h"

int		execute_node(t_exetree_node *exnode, int *parent_fd, t_exe_info *info);
void	executor(t_exetree_node *exnode, t_exe_info *info);
int		calc_exit_status(int ws);
int		exe_and(t_exetree_node *exnode, int *parent_fd, t_exe_info *info);
int		exe_or(t_exetree_node *exnode, int *parent_fd, t_exe_info *info);
int		exe_pipe(t_exetree_node *exnode, int *parent_fd, t_exe_info *info);
int		exe_redir(t_exetree_node *exnode, int *parent_fd, t_exe_info *info);
void	close_fd(t_exetree_node *exnode, t_exe_info *info);
void	close_inout_fd(t_exetree_node *exnode);
void	close_pipes(t_exe_info *info);
void	close_unused_pipe(t_exetree_node *exnode,t_exe_info *info);
void	inherit_parent_fd(t_exetree_node *exnode, int *parent_fd);
void	restore_std_fd();

#endif
