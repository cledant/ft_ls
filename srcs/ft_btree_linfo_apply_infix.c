/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_linfo_apply_infix.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 20:20:55 by cledant           #+#    #+#             */
/*   Updated: 2016/01/13 14:13:05 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_btree_linfo_apply_infix(t_btree *root, t_linfo *pad, t_option *opt)
{
	if (root->left != NULL)
		ft_btree_linfo_apply_infix(root->left, pad, opt);
	if (opt->hidden == 0)
		ft_display_l_all(root->content, pad);
	else
		ft_display_l_no_dot(root->content, pad);
	if (root->right != NULL)
		ft_btree_linfo_apply_infix(root->right, pad, opt);
}
