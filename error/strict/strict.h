/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strict.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 01:45:04 by mypark            #+#    #+#             */
/*   Updated: 2022/04/10 21:20:34 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRICT_H
# define STRICT_H
# include <sys/types.h>
# include <dirent.h>

int		strict_dup(int fd);
int		strict_open(char *filename, int oflag, int right);
int		strict_waitpid(pid_t pid, int *ws, int opt);
int		strict_write(int fd, char *buf, int len);
pid_t	strict_fork(void);
void	*strict_malloc(int size, int count);
void	strict_close(int fd);
void	strict_dup2(int srcfd, int dstfd);
void	strict_execve(char *cmd, char **args, char **envp);
void	strict_pipe(int *pipefd);
void	strict_putstr_fd(char *str, int fd);
DIR		*strict_opendir(char *dir_name);
void	strict_closedir(DIR *dir_ptr);

#endif
