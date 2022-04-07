/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 23:59:32 by mypark            #+#    #+#             */
/*   Updated: 2022/04/08 00:00:04 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H
# include "info.h"
# include "exe_tree.h"

int	exe_builtin(t_exetree_node *exe_node, t_exe_info *e_info);
int	is_builtin(char *cmd);
int	builtin_cd(t_exetree_node *exe_node);
int	builtin_pwd(t_exetree_node *exe_node);
int	builtin_exit(t_exe_info *info);
int	builtin_export(t_exetree_node *exe_node, t_exe_info *info);
int	builtin_env(t_exe_info *info);
int	builtin_echo(t_exetree_node *exe_node);
int	builtin_unset(t_exetree_node *exe_node, t_exe_info *info);

#endif
