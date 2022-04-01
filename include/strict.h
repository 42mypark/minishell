/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strict.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 01:45:04 by mypark            #+#    #+#             */
/*   Updated: 2022/04/01 14:29:39 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRICT_H
# define STRICT_H
# include <sys/types.h>

void	*strict_malloc(int size, int count);
pid_t	strict_fork();
void	strict_dup2(int srcfd, int dstfd);
void	strict_close(int fd);

#endif
