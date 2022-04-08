/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 01:28:21 by mypark            #+#    #+#             */
/*   Updated: 2022/04/08 18:55:25 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	EXECUTION_H
# define EXECUTION_H
# include "exe_tree.h"
# include "info.h"

int	calc_exit_status(int ws);
int	exe_and(t_exetree_node *exnode, int *parent_fd, t_exe_info *info);
int	exe_or(t_exetree_node *exnode, int *parent_fd, t_exe_info *info);
int	exe_pipe(t_exetree_node *exnode, int *parent_fd, t_exe_info *info);
int	exe_redir(t_exetree_node *exnode, int *parent_fd, t_exe_info *info);
int	exe_error(t_exetree_node *exnode, t_exe_info *info);
int	execute_node(t_exetree_node *exnode, int *parent_fd, t_exe_info *info);

#endif
