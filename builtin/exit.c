/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:07:41 by mypark            #+#    #+#             */
/*   Updated: 2022/04/12 03:39:24 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "error.h"
#include <errno.h>
#include <string.h>
#include "executor.h"
#include "strict.h"
#include "error.h"
#include "constant.h"
#include "exe_tree.h"

static int	is_exit_number(char *str)
{
	int				i;
	unsigned int	number;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (i == (int)ft_strlen(str))
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	number = 0;
	while (ft_isdigit(str[i]))
	{
		if (number > 2147483647)
			return (0);
		number = number * 10 + (str[i] - '0');
		i++;
	}
	while (str[i] && str[i] == ' ')
		i++;
	if (i != (int)ft_strlen(str))
		return (0);
	return (1);
}

int	builtin_exit(t_exetree_node *exnode, t_exe_info *info)
{
	t_cmd_info	*cmd;
	int			is_num;

	strict_putstr_fd("exit\n", 2);
	cmd = exnode->cmd;
	if (cmd->args[1] == FT_NULL)
		exit(info->last_exit);
	is_num = is_exit_number(cmd->args[1]);
	if (is_num && cmd->args[2] == FT_NULL)
		exit((unsigned char)ft_atoi(cmd->args[1]));
	if (is_num && cmd->args[2])
	{
		print_strerror("exit", FT_NULL, ERRMSG_EXIT_MANYARGS);
		return (1);
	}
	print_strerror("exit", cmd->args[1], ERRMSG_EXIT_NOTNUM);
	exit(255);
}
