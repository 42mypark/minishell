/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_exit_status.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 01:35:51 by mypark            #+#    #+#             */
/*   Updated: 2022/04/22 07:59:50 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	wstatus(int ws)
{
	return (ws & 0177);
}

static int	wifexited(int ws)
{
	if (wstatus(ws) == 0)
		return (1);
	return (0);
}

static int	wifsignaled(int ws)
{
	if (wstatus(ws) != 0177 && wstatus(ws) != 0)
		return (1);
	return (0);
}

static int	wifstopped(int ws)
{
	if (wstatus(ws) == 0177 && (ws >> 8) != 0x13)
		return (1);
	return (0);
}

int	calc_exit_status(int ws)
{
	if (wifexited(ws))
		return ((ws >> 8) & 0x000000ff);
	if (wifsignaled(ws))
		return (wstatus(ws) + 128);
	if (wifstopped(ws))
		return (ws >> 8);
	return (ws & 0200);
}
