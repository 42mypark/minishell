/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error_print.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 20:45:32 by mypark            #+#    #+#             */
/*   Updated: 2022/03/23 01:40:34 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_unexpected_token(char *later)
{
	ft_putstr_fd("syntax error near unexpected token \'", 2);
	ft_putstr_fd(later, 2);
	ft_putstr_fd("\'\n", 2);
	exit(258);
}

void	print_incorrect_pairs(char *type)
{
	ft_putstr_fd("syntax error incorrect pairs of \'", 2);
	ft_putstr_fd(type, 2);
	ft_putstr_fd("\'\n", 2);
	exit(258);
}
