/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:36:25 by mypark            #+#    #+#             */
/*   Updated: 2022/04/06 22:02:16 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H
# include "info.h"
# include "exe_tree.h"

int	builtin_cd(t_exetree_node *exe_node);
int	exe_builtin(t_exetree_node *exe_node, t_exe_info *e_info);
int	is_builtin(char *);
int	builtin_pwd(t_exetree_node *exe_node);
int	builtin_exit(t_exe_info *info);

#endif