/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_expander_utils.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 23:35:11 by mypark            #+#    #+#             */
/*   Updated: 2022/04/02 02:52:13 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_EXPANDER_UTILS_H
# define ENV_EXPANDER_UTILS_H
# include "env_expander.h"

int	env_expander_chars(\
	t_env_expander *envexp, \
	char input\
);
int	env_expander_double_quote(\
	t_env_expander *envexp, \
	char input\
);
int	env_expander_single_quote(\
	t_env_expander *envexp, \
	char input\
);
int	env_expander_dollar(\
	t_env_expander *envexp, \
	char input\
);
int	env_expander_dq_dollar(\
	t_env_expander *envexp, \
	char input\
);

#endif
