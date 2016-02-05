/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_sort_dir.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 14:47:08 by cledant           #+#    #+#             */
/*   Updated: 2016/01/17 08:53:22 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"
#include <dirent.h>

static t_btree	*ft_btree_sort_dir_p1(struct dirent *dir, char *path)
{
	t_btree		*root;
	t_mstat		*saved;

	root = NULL;
	if ((root = ft_btree_new(NULL, 0)) == NULL)
		return (NULL);
	if ((saved = ft_mstat_new(dir->d_namlen)) == NULL)
	{
		ft_memdel((void **)&root);
		return (NULL);
	}
	else
	{
		root->content = saved;
		if ((ft_mstat_save(path, dir, saved)) == -1)
		{
			ft_btree_del_all_0_size_node(&root);
			return (NULL);
		}
	}
	return (root);
}

static t_btree	*ft_btree_sort_dir_p2_5(struct dirent *dir,
					t_mstat **saved, t_btree *root)
{
	t_btree			*new;

	new = NULL;
	if ((new = ft_btree_new(NULL, 0)) == NULL)
	{
		ft_btree_del_all_0_size_node(&root);
		return (NULL);
	}
	if ((*saved = ft_mstat_new(dir->d_namlen)) == NULL)
	{
		ft_btree_del_all_0_size_node(&root);
		ft_memdel((void **)&new);
		return (NULL);
	}
	return (new);
}

static t_btree	*ft_btree_sort_dir_p2(struct dirent *dir, t_btree *root,
					char *path, int sort)
{
	t_btree		*new;
	t_mstat		*saved;

	new = NULL;
	saved = NULL;
	if ((new = ft_btree_sort_dir_p2_5(dir, &saved, root)) == NULL)
		return (NULL);
	else
	{
		new->content = saved;
		if ((ft_mstat_save(path, dir, saved)) == -1)
		{
			ft_btree_del_all_0_size_node(&root);
			return (NULL);
		}
		if (sort == 0)
			ft_btree_add_node(root, new, &ft_mstat_compare_name);
		else
			ft_btree_add_node(root, new, &ft_mstat_compare_time);
	}
	return (root);
}

static t_btree	*ft_btree_sort_dir_p0_5(DIR *ptr_dir,
					struct dirent *dir, char *path, int sort)
{
	t_mstat			*saved;
	t_btree			*root;

	saved = NULL;
	if ((root = ft_btree_sort_dir_p1(dir, path)) == NULL)
	{
		closedir(ptr_dir);
		return (NULL);
	}
	while ((dir = readdir(ptr_dir)) != NULL)
	{
		if ((root = ft_btree_sort_dir_p2(dir, root, path,
						sort)) == NULL)
		{
			closedir(ptr_dir);
			return (NULL);
		}
	}
	closedir(ptr_dir);
	return (root);
}

t_btree			*ft_btree_sort_dir(char *path, int sort)
{
	DIR				*ptr_dir;
	struct dirent	*dir;
	t_btree			*root;

	ptr_dir = opendir(path);
	if (ptr_dir == NULL)
		return (NULL);
	else
	{
		if ((dir = readdir(ptr_dir)) != NULL)
		{
			if ((root = ft_btree_sort_dir_p0_5(ptr_dir, dir,
							path, sort)) == NULL)
				return (NULL);
		}
		else
		{
			closedir(ptr_dir);
			return (NULL);
		}
	}
	return (root);
}
