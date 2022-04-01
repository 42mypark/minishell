/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 13:23:58 by mypark            #+#    #+#             */
/*   Updated: 2022/04/01 20:35:15 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H
# include "token.h"

enum e_error
{
	ERROR_MALLOC,
};

void	syntax_error_check(t_tokens *tks);
void	print_malloc_error(void);
void	print_strerror(char *func, char *msg);

#endif
