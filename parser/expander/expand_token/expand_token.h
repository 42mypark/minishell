/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_token.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 01:25:46 by mypark            #+#    #+#             */
/*   Updated: 2022/04/06 22:28:38 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_TOKEN_H
# define EXPAND_TOKEN_H
# include "token.h"
# include "info.h"

t_tokens	*expand_token_env(t_token *tk, t_exe_info *info);
t_tokens	*expand_token_wildcard(t_token *tk, t_exe_info *info);
t_tokens	*expand_token_quote(t_token *tk, t_exe_info *info);

#endif
