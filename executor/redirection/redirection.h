/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 23:35:11 by mypark            #+#    #+#             */
/*   Updated: 2022/04/08 17:21:12 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTION_H
# define REDIRECTION_H
# include "exe_tree.h"
# include "parse_tree.h"
# include "info.h"

int				make_cmd(t_parsetree_node *p_nd, t_exetree_node *e_nd, t_exe_info *info);
void			make_exe_pipe(t_parsetree_node *p_nd, t_exetree_node *e_nd, t_exe_info *info);
void			make_exe_redir(t_parsetree_node *p_nd, t_exetree_node *e_nd, t_exe_info *info);
t_exetree_node	*make_exetree(t_parsetree_node *p_nd, t_exe_info *info);

#endif
