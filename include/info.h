/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 01:28:21 by mypark            #+#    #+#             */
/*   Updated: 2022/04/01 00:00:13 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	INFO_H
# define INFO_H
# include "libft.h"

typedef struct s_err_info
{
	int			exit_status;
	const char	*msg;
}				t_err_info;

typedef struct s_cmd_info
{
	char	*cmd;
	char	**args;
	char	**envp;
}				t_cmd_info;

typedef struct s_exe_info
{
	t_list	*pipes;
	t_list	*pids;
	char	**envp;
}				t_exe_info;

t_err_info		*new_err_info(const char *msg, int exit_status);
void			free_err_info(t_err_info *info);
t_cmd_info		*new_cmd_info(char *cmd, char **args, char **envp);
void			free_cmd_info(t_cmd_info *info);
t_exe_info		*new_exe_info(char **envp);
void			insert_new_pipe(t_exe_info *info, int *pipe);
void			insert_new_pid(t_exe_info *info, int pid);
void			free_exe_info(t_exe_info *info);

#endif
