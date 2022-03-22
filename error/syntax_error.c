/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:46:50 by mypark            #+#    #+#             */
/*   Updated: 2022/03/22 20:55:15 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "error_utils.h"

void	syntax_error_check(t_tokens *tks)
{
	syntax_unexpected_token(tks);
}
