/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constant.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 02:32:55 by mypark            #+#    #+#             */
/*   Updated: 2022/04/09 04:12:02 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANT_H
# define CONSTANT_H

# ifndef NULL
#  define NULL	'\0'
# endif

# define ERRMSG_UNSET_NOVALID	"not a valid identifier"
# define ERRMSG_EXPORT_NOVALID	"not a valid identifier"
# define ERRMSG_ENV_NOFILE		"No such file or directory"
# define ERRMSG_EXIT_NOTNUM		"numeric argument required"
# define ERRMSG_EXIT_MANYARGS	"too many arguments"

# define ERRMSG_GETCWD			"cannot get the currently working directory"
#endif
