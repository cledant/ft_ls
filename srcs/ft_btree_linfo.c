/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_linfo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 16:13:32 by cledant           #+#    #+#             */
/*   Updated: 2016/01/16 15:18:40 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

void	ft_infix_reverse_dir(t_btree *root, t_option *opt, t_linfo *l_stat)
{
	t_mstat *stat;

	if (root->right != NULL)
		ft_infix_reverse_dir(root->right, opt, l_stat);
	stat = root->content;
	{
		if (ft_mstat_explore_hidden(stat, opt->hidden) == 1 &&
				ft_mstat_is_content_null(stat) == 0)
			ft_linfo_btree_compare_size(root, l_stat);
	}
	if (root->left != NULL)
		ft_infix_reverse_dir(root->left, opt, l_stat);
}

void	ft_infix_dir(t_btree *root, t_option *opt, t_linfo *l_stat)
{
	t_mstat *stat;

	if (root->left != NULL)
		ft_infix_dir(root->left, opt, l_stat);
	stat = root->content;
	{
		if (ft_mstat_explore_hidden(stat, opt->hidden) == 1 &&
				ft_mstat_is_content_null(stat) == 0)
			ft_linfo_btree_compare_size(root, l_stat);
	}
	if (root->right != NULL)
		ft_infix_dir(root->right, opt, l_stat);
}

void	ft_btree_linfo(t_btree *root, t_option *opt, t_linfo *l_stat)
{
	if (root->right == NULL && root->left == NULL)
	{
		ft_linfo_btree_compare_size(root, l_stat);
		return ;
	}
	if (opt->reverse == 0)
		ft_infix_dir(root, opt, l_stat);
	else if (opt->reverse == 1)
		ft_infix_reverse_dir(root, opt, l_stat);
}
