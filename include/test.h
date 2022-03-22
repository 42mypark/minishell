/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 01:45:04 by mypark            #+#    #+#             */
/*   Updated: 2022/03/22 22:21:49 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "token.h"
# include "tokenizer_utils.h"
# include "parse_tree.h"

void	print_tokens(t_tokens *tks);
void	print_parsetree(t_parsetree_node *node);
void	print_parsetree_node(t_parsetree_node *node);

#endif
