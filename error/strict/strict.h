/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strict.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 01:45:04 by mypark            #+#    #+#             */
/*   Updated: 2022/04/09 19:45:18 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRICT_H
# define STRICT_H
# include <sys/types.h>

int		strict_dup(int fd);
int		strict_open(char *filename, int oflag, int right);
int		strict_waitpid(pid_t pid, int *ws, int opt);
pid_t	strict_fork(void);
void	*strict_malloc(int size, int count);
void	strict_close(int fd);
void	strict_dup2(int srcfd, int dstfd);
void	strict_execve(char *cmd, char **args, char **envp);
void	strict_pipe(int *pipefd);

#endif
