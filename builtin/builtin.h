/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:36:25 by mypark            #+#    #+#             */
/*   Updated: 2022/04/07 02:00:48 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H
# include "info.h"
# include "exe_tree.h"

int	exe_builtin(t_exetree_node *exe_node, t_exe_info *e_info);
int	is_builtin(char *);
int	builtin_cd(t_exetree_node *exe_node);
int	builtin_pwd(t_exetree_node *exe_node);
int	builtin_exit(t_exe_info *info);
int	builtin_export(t_exetree_node *exe_node, t_exe_info *info);


#endif
