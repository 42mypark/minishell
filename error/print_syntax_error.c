/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error_print.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 20:45:32 by mypark            #+#    #+#             */
/*   Updated: 2022/03/23 02:50:45 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "token.h"

void	print_unexpected_token(t_tokens *tks, char *later)
{
	ft_putstr_fd("syntax error near unexpected token \'", 2);
	ft_putstr_fd(later, 2);
	ft_putstr_fd("\'\n", 2);
	free_tokens(tks);
	exit(258);
}

void	print_incorrect_pairs(t_tokens *tks, char *type)
{
	ft_putstr_fd("syntax error incorrect pairs of \'", 2);
	ft_putstr_fd(type, 2);
	ft_putstr_fd("\'\n", 2);
	free_tokens(tks);
	exit(258);
}
