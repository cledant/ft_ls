/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_to_screen.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 10:00:30 by cledant           #+#    #+#             */
/*   Updated: 2016/01/17 10:10:55 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

static void		ft_infix_path_dir_reverse(t_btree *root, t_option *opt,
					int flag, int *space)
{
	t_ssort		*file;

	file = root->content;
	if (root->right != NULL)
		ft_infix_path_dir_reverse(root->right, opt, flag, space);
	if (file->is_dir == 1 || (opt->detail == 0 &&
				ft_is_path_link_a_dir(file->name) == 1))
	{
		if (*space != 0)
			ft_putendl("");
		if (flag == 1)
			ft_putendl_colon(file->name);
		*space = 1;
		ft_option_ls(file->name, opt, NULL);
	}
	if (root->left != NULL)
		ft_infix_path_dir_reverse(root->left, opt, flag, space);
}

static void		ft_infix_path_reverse(t_btree *root, t_option *opt, int *space,
					t_linfo *lstat)
{
	t_ssort		*file;

	file = root->content;
	if (root->right != NULL)
		ft_infix_path_reverse(root->right, opt, space, lstat);
	if (file->is_dir == 0 && (opt->detail == 1 ||
				ft_is_path_link_a_dir(file->name) != 1))
	{
		if (ft_option_ls(file->name, opt, lstat) == 0)
		{
			*space = 1;
		}
	}
	if (root->left != NULL)
		ft_infix_path_reverse(root->left, opt, space, lstat);
}

static void		ft_infix_path_dir(t_btree *root, t_option *opt, int flag,
					int *space)
{
	t_ssort		*file;

	file = root->content;
	if (root->left != NULL)
		ft_infix_path_dir(root->left, opt, flag, space);
	if (file->is_dir == 1 || (opt->detail == 0 &&
				ft_is_path_link_a_dir(file->name) == 1))
	{
		if (*space != 0)
			ft_putendl("");
		if (flag == 1)
			ft_putendl_colon(file->name);
		*space = 1;
		ft_option_ls(file->name, opt, NULL);
	}
	if (root->right != NULL)
		ft_infix_path_dir(root->right, opt, flag, space);
}

static void		ft_infix_path(t_btree *root, t_option *opt, int *space,
					t_linfo *lstat)
{
	t_ssort		*file;

	file = root->content;
	if (root->left != NULL)
		ft_infix_path(root->left, opt, space, lstat);
	if (file->is_dir == 0 && (opt->detail == 1 ||
				ft_is_path_link_a_dir(file->name) != 1))
	{
		if (ft_option_ls(file->name, opt, lstat) == 0)
			*space = 1;
	}
	if (root->right != NULL)
		ft_infix_path(root->right, opt, space, lstat);
}

void			ft_put_to_screen(t_btree *root, t_option *opt, int flag,
				int *space)
{
	t_linfo		l_stat;

	ft_linfo_init(&l_stat);
	ft_linfo_fill(root, opt, &l_stat);
	if (opt->reverse == 0)
	{
		ft_infix_path(root, opt, space, &l_stat);
		ft_infix_path_dir(root, opt, flag, space);
	}
	else
	{
		ft_infix_path_reverse(root, opt, space, &l_stat);
		ft_infix_path_dir_reverse(root, opt, flag, space);
	}
}
