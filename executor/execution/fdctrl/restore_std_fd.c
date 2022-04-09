/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restore_std_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 02:31:21 by mypark            #+#    #+#             */
/*   Updated: 2022/04/08 02:00:33 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strict.h"
#include "exe_tree.h"

void	restore_std_fd(t_exe_info *info)
{
	strict_dup2(info->std_out, 1);
	strict_dup2(info->std_in, 0);
}
