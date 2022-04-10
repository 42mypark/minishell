/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdctrl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 01:46:22 by mypark            #+#    #+#             */
/*   Updated: 2022/04/10 18:12:15 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDCTRL_H
# define FDCTRL_H
# include "info.h"
# include "exe_tree.h"

void	close_fd(t_exetree_node *exnode, t_exe_info *info);
void	close_myinout_fd(t_exetree_node *exnode);
void	close_pipes(t_exe_info *info);
void	close_unused_pipe(t_exetree_node *exnode, t_exe_info *info);
void	receive_parent_fd(t_exetree_node *exnode, int *parent_fd);
void	restore_std_fd(t_exe_info *info);

#endif
