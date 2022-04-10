/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 23:59:32 by mypark            #+#    #+#             */
/*   Updated: 2022/04/11 00:09:08 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H
# include "info.h"
# include "exe_tree.h"

int	is_builtin(char *cmd);
int	builtin_cd(t_exetree_node *exnode, t_exe_info *info);
int	builtin_pwd(void);
int	builtin_exit(t_exetree_node *exnode, t_exe_info *info);
int	builtin_export(t_exetree_node *exnode, t_exe_info *info);
int	builtin_env(t_exetree_node *exnode, t_exe_info *info);
int	builtin_echo(t_exetree_node *exnode);
int	builtin_unset(t_exetree_node *exnode, t_exe_info *info);

#endif
