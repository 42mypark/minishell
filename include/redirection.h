/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 01:46:22 by mypark            #+#    #+#             */
/*   Updated: 2022/03/30 20:17:36 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTION_H
# define REDIRECTION_H
# include "exe_tree.h"
# include "parse_tree.h"

t_exetree_node	*parse_to_exe(t_parsetree_node *p_nd, int infd, int outfd, char **envp);

#endif
