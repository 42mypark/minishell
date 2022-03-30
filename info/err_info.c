/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:51:01 by mypark            #+#    #+#             */
/*   Updated: 2022/03/31 01:25:31 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info.h"
#include "libft.h"
#include <stdlib.h>

t_err_info	*new_err_info(const char *msg, int exit_status)
{
	t_err_info *info;

	info = malloc(sizeof(t_err_info));
	info->msg = msg;
	info->exit_status = exit_status;
	return (info);
}

void	free_err_info(t_err_info *info)
{
	free(info);
}
