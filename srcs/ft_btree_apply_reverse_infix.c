/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_apply_reverse_infix.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 15:41:38 by cledant           #+#    #+#             */
/*   Updated: 2016/01/04 15:43:54 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_btree_apply_reverse_infix(t_btree *root, void (*applyf)(void *))
{
	if (root->right != NULL)
		ft_btree_apply_reverse_infix(root->right, applyf);
	(*applyf)(root->content);
	if (root->left != NULL)
		ft_btree_apply_reverse_infix(root->left, applyf);
}
