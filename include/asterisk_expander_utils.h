/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asterisk_expander_utils.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 23:35:11 by mypark            #+#    #+#             */
/*   Updated: 2022/03/24 14:40:24 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASTERISK_EXPANDER_UTILS_H
# define ASTERISK_EXPANDER_UTILS_H

typedef enum e_asterisk_epdr_state
{
	A_REJECT,
	A_SUCCESS,
	A_ASTERISK,
	A_COMPARE
}			t_asterisk_epdr_state;

t_asterisk_epdr_state	asterisk_epdr_compare(char **splited_format, char *file, int *wc, int *fi);
t_asterisk_epdr_state	asterisk_epdr_asterisk(char **splited_format, char *file, int *wc, int *fi);
int						asterisk_check_format(char *file, char *format);

#endif
