/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_ls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 11:37:35 by cledant           #+#    #+#             */
/*   Updated: 2016/01/17 09:04:33 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

static void		ft_infix_reverse_dir_ls(t_btree *root, char *path,
						t_option *opt)
{
	t_mstat	*stat;
	char	*new_path;
	char	*disp_new_path;

	if (root->right != NULL)
		ft_infix_reverse_dir_ls(root->right, path, opt);
	stat = root->content;
	if ((ft_mstat_is_content_dir(root->content) == 1) &&
				(ft_strcmp(".", stat->name) == 0 ||
					ft_strcmp("..", stat->name) == 0) != 1)
	{
		if (ft_mstat_explore_hidden(stat, opt->hidden) == 1)
		{
			new_path = ft_fuse_chain(path, stat->name);
			disp_new_path = ft_title_cap_r(new_path);
			ft_putendl("");
			ft_putendl(disp_new_path);
			ft_option_ls(new_path, opt, NULL);
			ft_strdel(&new_path);
			ft_strdel(&disp_new_path);
		}
	}
	if (root->left != NULL)
		ft_infix_reverse_dir_ls(root->left, path, opt);
}

static void		ft_infix_dir_ls(t_btree *root, char *path, t_option *opt)
{
	t_mstat *stat;
	char	*new_path;
	char	*disp_new_path;

	if (root->left != NULL)
		ft_infix_dir_ls(root->left, path, opt);
	stat = root->content;
	if ((ft_mstat_is_content_dir(root->content) == 1) &&
				(ft_strcmp(".", stat->name) == 0 ||
					ft_strcmp("..", stat->name) == 0) != 1)
	{
		if (ft_mstat_explore_hidden(stat, opt->hidden) == 1)
		{
			new_path = ft_fuse_chain(path, stat->name);
			disp_new_path = ft_title_cap_r(new_path);
			ft_putendl("");
			ft_putendl(disp_new_path);
			ft_option_ls(new_path, opt, NULL);
			ft_strdel(&new_path);
			ft_strdel(&disp_new_path);
		}
	}
	if (root->right != NULL)
		ft_infix_dir_ls(root->right, path, opt);
}

static void		ft_option_ls_part3(t_btree *root, t_option *opt,
					char *path, t_linfo *linfo)
{
	ft_option_what_to_display(root, opt, linfo);
	if (opt->all_dir == 1 && opt->reverse == 0)
		ft_infix_dir_ls(root, path, opt);
	else if (opt->all_dir == 1 && opt->reverse == 1)
		ft_infix_reverse_dir_ls(root, path, opt);
}

static int		ft_option_ls_part2(int link, t_btree **root, char *path,
					t_option *opt)
{
	if (link == 0 && (*root = ft_btree_sort_dir(path, opt->sort)) == NULL)
	{
		if ((*root = ft_btree_mstat_file(path)) == NULL)
		{
			ft_putstr_fd("ls: ", 2);
			perror(path);
			return (1);
		}
		if (ft_mstat_is_content_dir((*root)->content) == 1)
		{
			ft_putstr_fd("ls: ", 2);
			perror(path);
			ft_btree_del_all_0_size_node(root);
			return (1);
		}
	}
	if (opt->detail == 1 && link == 0)
		ft_display_blocksize(path, opt->hidden);
	return (0);
}

int				ft_option_ls(char *path, t_option *opt, t_linfo *linfo)
{
	t_btree		*root;
	int			link;
	t_mstat		*saved;

	root = NULL;
	link = 0;
	if (ft_is_path_link(path) == 1 && ft_lastchar_is_slash(path) == 0
		&& opt->detail == 1)
	{
		if ((root = ft_btree_mstat_file(path)) == NULL)
		{
			ft_putstr_fd("ls: ", 2);
			perror(path);
			return (1);
		}
		link = 1;
		saved = root->content;
		ft_strdel(&(saved->folder));
		saved->folder = ft_strnew(0);
	}
	if (ft_option_ls_part2(link, &root, path, opt) == 1)
		return (1);
	ft_option_ls_part3(root, opt, path, linfo);
	ft_btree_del_all_0_size_node(&root);
	return (0);
}
