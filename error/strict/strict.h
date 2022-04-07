/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strict.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 01:45:04 by mypark            #+#    #+#             */
/*   Updated: 2022/04/08 02:30:54 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRICT_H
# define STRICT_H
# include <sys/types.h>

void	*strict_malloc(int size, int count);
pid_t	strict_fork();
void	strict_dup2(int srcfd, int dstfd);
void	strict_close(int fd);
int		strict_open(char *filename, int oflag, int right);
void	strict_execve(char *cmd, char **args, char **envp);
int		strict_waitpid(pid_t pid, int *ws, int opt);
void	strict_pipe(int *pipefd);

#endif
