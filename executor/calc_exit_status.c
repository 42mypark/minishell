/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_exit_status.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 01:35:51 by mypark            #+#    #+#             */
/*   Updated: 2022/04/06 21:48:08 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	wstatus(int ws)
{
	return (ws & 0177);
}

static int	wifexited(int ws)
{
	if (wstatus(ws) == 0)
		return 1;
	return (0);
}

static int	wifsignaled(int ws)
{
	if (wstatus(ws) != 0x00000008 && wstatus(ws) != 0)
		return 1;
	return (0);
}

int	calc_exit_status(int ws)
{
	if (wifexited(ws))
		return ((ws & 0xff00) >> 8);
	if (wifsignaled(ws))
		return (wstatus(ws) + 128);
	return (ws >> 8);
}
