/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_mstat_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 19:05:47 by cledant           #+#    #+#             */
/*   Updated: 2016/01/16 17:53:45 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

static void	ft_btree_mstat_file_part2(t_mstat *saved, struct stat v_stat,
				char *path)
{
	struct timespec		v_timespec;

	v_timespec = v_stat.st_mtimespec;
	saved->mod_time = v_timespec.tv_sec;
	saved->dev = v_stat.st_dev;
	saved->mode = v_stat.st_mode;
	saved->hardlink = v_stat.st_nlink;
	saved->inode = v_stat.st_ino;
	saved->uid = v_stat.st_uid;
	saved->gid = v_stat.st_gid;
	saved->rdev = v_stat.st_rdev;
	saved->size = v_stat.st_size;
	saved->has_xattr = listxattr(path, NULL, 0, XATTR_NOFOLLOW);
}

t_btree		*ft_btree_mstat_file(char *path)
{
	t_btree				*root;
	t_mstat				*saved;
	struct stat			v_stat;

	if ((saved = ft_mstat_new(ft_strlen(path))) == NULL)
		return (NULL);
	if ((root = ft_btree_new(NULL, 0)) == NULL)
	{
		ft_memdel((void **)&saved);
		return (NULL);
	}
	ft_strcpy(saved->name, path);
	saved->namelen = ft_strlen(path);
	root->content = saved;
	if ((saved->folder = ft_strnew(1)) == NULL)
	{
		ft_memdel((void **)&saved);
		ft_memdel((void **)&root);
		return (NULL);
	}
	ft_strcpy(saved->folder, ".");
	if (lstat(path, &v_stat) == -1)
		return (root);
	ft_btree_mstat_file_part2(saved, v_stat, path);
	return (root);
}
