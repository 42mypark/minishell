/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:21:57 by mypark            #+#    #+#             */
/*   Updated: 2022/03/25 20:34:59 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_tree.h"

void	quote_removal(t_tokens *tks)
{
	if (tks == NULL || tks->head == NULL)
		return ;
	
}

void	remove_quote(t_parsetree_node *node)
{
	if (node->type == TOKENS)
		quote_removal(node->tokens);
	remove_quote(node->left);
	remove_quote(node->right);
}