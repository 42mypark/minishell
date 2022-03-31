/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_utils.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 23:35:11 by mypark            #+#    #+#             */
/*   Updated: 2022/03/31 18:19:45 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTION_UTILS_H
# define REDIRECTION_UTILS_H
# include "exe_tree.h"
# include "parse_tree.h"
# include "info.h"

void			listen_heredoc_quoted(char *limiter, int to);
t_exetree_node	*make_exetree_node(t_parsetree_node *p_nd, int infd, int outfd, t_exe_info *info);
int				meet_redir(t_parsetree_node *p_nd, t_exetree_node *e_nd, t_exe_info *info);
int				make_cmd(t_parsetree_node *p_nd, t_exetree_node *e_nd, t_exe_info *info);
void			listen_heredoc(char *limiter, int to, char **envp);



#endif
