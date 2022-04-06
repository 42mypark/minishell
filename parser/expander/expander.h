/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 01:46:22 by mypark            #+#    #+#             */
/*   Updated: 2022/04/06 22:29:45 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H
# include "parse_tree.h"
# include "token.h"
# include "info.h"

void	wildcard_expander(t_tokens *tks, t_token *tk);
void	env_expander(t_tokens *tks, char *str, t_exe_info *info);
void	quote_remover(t_tokens *tks, t_token *tk);
void	expander(t_parsetree_node *node, t_exe_info *info);

#endif
