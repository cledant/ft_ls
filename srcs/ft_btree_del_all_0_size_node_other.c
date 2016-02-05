/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_del_all_0_size_node_other.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 16:33:50 by cledant           #+#    #+#             */
/*   Updated: 2016/01/12 16:40:10 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"
#include "ft_ls.h"

static void		ft_postfix_del_node(t_btree *root, void (*applyf)(void *))
{
	if (root->left != NULL)
		ft_postfix_del_node(root->left, applyf);
	if (root->right != NULL)
		ft_postfix_del_node(root->right, applyf);
	(*applyf)(root);
}

void			ft_btree_del_all_0_size_node_other(t_btree **alst)
{
	if (*alst == NULL)
		return ;
	ft_btree_apply_postfix(*alst, &ft_ssort_del);
	ft_postfix_del_node(*alst, &free);
	*alst = NULL;
}
