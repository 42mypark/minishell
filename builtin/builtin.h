/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:36:25 by mypark            #+#    #+#             */
/*   Updated: 2022/04/04 19:21:24 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H
# include "info.h"

int	builtin_cd(char *dir, char **envp);
int	builtin(t_cmd_info *info);
int	is_builtin(char *cmd);
int	builtin_pwd(void);

#endif