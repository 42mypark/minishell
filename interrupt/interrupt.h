/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interrupt.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 23:35:11 by mypark            #+#    #+#             */
/*   Updated: 2022/04/22 07:50:21 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERRUPT_H
# define INTERRUPT_H

void	ctrl_c(int sig);
void	ctrl_c2(int sig);
void	ctrl_c_heredoc(int sig);
void	ctrl_quit(int sig);

#endif
