/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_del_all_node.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 17:19:59 by cledant           #+#    #+#             */
/*   Updated: 2016/01/16 15:17:10 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"
#include "ft_ls.h"

static void		ft_postfix_del_content(t_btree *root, void (*applyf)
					(void *, size_t))
{
	if (root->left != NULL)
		ft_postfix_del_content(root->left, applyf);
	if (root->right != NULL)
		ft_postfix_del_content(root->right, applyf);
	(*applyf)(root->content, root->content_size);
}

static void		ft_postfix_del_node(t_btree *root, void (*applyf)(void *))
{
	if (root->left != NULL)
		ft_postfix_del_node(root->left, applyf);
	if (root->right != NULL)
		ft_postfix_del_node(root->right, applyf);
	(*applyf)(root);
}

void			ft_btree_del_all_node(t_btree **alst)
{
	if (*alst == NULL)
		return ;
	ft_postfix_del_content(*alst, &ft_free_content);
	ft_postfix_del_node(*alst, &free);
	*alst = NULL;
}
