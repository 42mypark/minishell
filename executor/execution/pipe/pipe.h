/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 01:46:22 by mypark            #+#    #+#             */
/*   Updated: 2022/04/10 18:11:03 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_H
# define PIPE_H
# include "info.h"

enum e_pipe_position
{
	PIPE_LAST,
	PIPE_NOT_LAST
};

int		*generate_pipe(void);
void	set_pipe(int **pipefd, enum e_pipe_position pos, t_exe_info *info);

#endif
