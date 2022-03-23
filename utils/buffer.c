/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:36:47 by mypark            #+#    #+#             */
/*   Updated: 2022/03/24 01:46:35 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	init_buffer(char *buf, int *len)
{
	*len = 0;
	buf[(*len)] = '\0';
}

void	push_buffer(char *buf, char input, int *len)
{
	buf[(*len)++] = input;
	buf[(*len)] = '\0';
}
