/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_token.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 01:25:46 by mypark            #+#    #+#             */
/*   Updated: 2022/04/02 01:26:17 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_TOKEN_H
# define EXPAND_TOKEN_H
# include "token.h"

t_tokens	*expand_token_env(t_token *tk, char **envp);
t_tokens	*expand_token_wildcard(t_token *tk, char **envp);
t_tokens	*expand_token_quote(t_token *tk, char **envp);

#endif
