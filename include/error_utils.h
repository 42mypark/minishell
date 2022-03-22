/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 13:23:58 by mypark            #+#    #+#             */
/*   Updated: 2022/03/23 02:46:51 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_UTILS_H
# define ERROR_UTILS_H
# include "token.h"

struct s_table
{
	int	(*table)[12];
};

void	print_unexpected_token(t_tokens *tks, char *later);
void	print_incorrect_pairs(t_tokens *tks, char *type);
void	syntax_unexpected_token(t_tokens *tks);
void	syntax_incorrect_pairs(t_tokens *tks);

#endif
