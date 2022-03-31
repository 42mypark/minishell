/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 01:46:22 by mypark            #+#    #+#             */
/*   Updated: 2022/03/31 17:19:21 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H
# include "parse_tree.h"

void	expand_wildcard(t_parsetree_node *head, char **envp);
void	expand_env(t_parsetree_node *head, char **envp);
void	remove_quote(t_parsetree_node *node, char **envp);
void	env_expander(t_tokens *tks, char *str, char **envp);

#endif
