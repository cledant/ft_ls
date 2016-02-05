/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linfo_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 10:06:04 by cledant           #+#    #+#             */
/*   Updated: 2016/01/17 11:12:17 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

void	ft_linfo_fill(t_btree *root, t_option *opt, t_linfo *lstat)
{
	t_ssort		*file;
	t_btree		*new;

	file = root->content;
	if (root->left != NULL)
		ft_linfo_fill(root->left, opt, lstat);
	if (file->is_dir == 0 && (opt->detail == 1 ||
				ft_is_path_link_a_dir(file->name) != 1))
	{
		if ((new = ft_btree_mstat_file(file->name)) == NULL)
		{
			ft_putendl_fd("ls :", 2);
			perror(file->name);
		}
		if (ft_mstat_explore_hidden(new->content, opt->hidden) == 1 &&
				ft_mstat_is_content_null(new->content) == 0)
			ft_linfo_btree_compare_size(new, lstat);
		ft_btree_del_all_0_size_node(&new);
	}
	if (root->right != NULL)
		ft_linfo_fill(root->right, opt, lstat);
}
