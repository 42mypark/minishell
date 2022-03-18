/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:55:44 by mypark            #+#    #+#             */
/*   Updated: 2022/03/18 17:58:47 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_tree.h"

t_pt_node	*new_pt_node(t_tokens *tks, t_pt_node *parent)
{
	t_pt_node	*new;

	new = malloc(sizeof(t_pt_node));
	if (new == NULL)
		return (NULL);
	new->left = NULL;
	new->right = NULL;
	new->parent = parent;
	new->tokens = tks;
	new->parsed = 0;
	return (new);
}
