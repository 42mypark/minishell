/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 23:35:11 by mypark            #+#    #+#             */
/*   Updated: 2022/04/08 17:13:28 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H
# include "exe_tree.h"
# include "token.h"
# include "info.h"

void	listen_heredoc_quoted(char *limiter, int to);
void	listen_heredoc(char *limiter, int to, t_exe_info *info);
void	make_heredoc(t_exetree_node *e_nd, t_token *tk, t_exe_info *info)

#endif
