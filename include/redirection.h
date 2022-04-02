/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 01:46:22 by mypark            #+#    #+#             */
/*   Updated: 2022/03/31 01:47:50 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTION_H
# define REDIRECTION_H
# include "exe_tree.h"
# include "parse_tree.h"
# include "info.h"

t_exetree_node	*make_exetree(t_parsetree_node *p_nd, t_exe_info *info);

#endif