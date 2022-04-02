
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 01:45:04 by mypark            #+#    #+#             */
/*   Updated: 2022/03/31 22:05:26 by mypark           ###   ########.fr       */
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
# include "parser.h"
# include "error.h"
# include "tokenizer.h"
# include "expander.h"
# include "../parser/expander/expansion_record.h"
# include "exe_tree.h"
# include "redirection.h"
# include "info.h"
# include "../parser/expander/env/env_expander.h"
# include "executor.h"
#include <string.h>
#include <errno.h>


void	print_tokens(t_tokens *tks);
void	print_parsetree(t_parsetree_node *node, int *cnt);
void	print_parsetree_node(t_parsetree_node *node, int *cnt);
void	print_expansion_record(t_expansion_record *rec);
void	print_expansion_range(t_expansion_range *range);
char	*enum_token_to_str(enum e_token type);
void	print_splited(char **splited);
void	print_exetree(t_exetree_node *node, int *cnt);
void	print_exetree_node(t_exetree_node *node, int *cnt);
void	print_cmd_info(t_cmd_info *info);
void	print_err_info(t_err_info *info);
void	print_exe_info(t_exe_info *info);

#endif
