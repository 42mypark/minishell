/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_syntax_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 20:45:32 by mypark            #+#    #+#             */
/*   Updated: 2022/04/22 08:28:34 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strict.h"

void	print_unexpected_token(char *later)
{
	strict_putstr_fd("syntax error near unexpected token \'", 2);
	strict_putstr_fd(later, 2);
	strict_putstr_fd("\'\n", 2);
}

void	print_incorrect_pairs(char *type)
{
	strict_putstr_fd("syntax error incorrect pairs of \'", 2);
	strict_putstr_fd(type, 2);
	strict_putstr_fd("\'\n", 2);
}
