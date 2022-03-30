/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 13:23:58 by mypark            #+#    #+#             */
/*   Updated: 2022/03/30 19:02:10 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_UTILS_H
# define ERROR_UTILS_H
# include "token.h"

void	print_unexpected_token(t_tokens *tks, char *later);
void	print_incorrect_pairs(t_tokens *tks, char *type);
void	syntax_unexpected_token(t_tokens *tks);
void	syntax_incorrect_pairs(t_tokens *tks);

#endif
