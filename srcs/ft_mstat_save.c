/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mstat_save.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 17:52:52 by cledant           #+#    #+#             */
/*   Updated: 2016/01/16 17:42:04 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "ft_ls.h"

static void		ft_mstat_save_part2(t_mstat *saved, char *fullpath,
					struct stat v_stat)
{
	acl_t	acl;

	saved->dev = v_stat.st_dev;
	saved->mode = v_stat.st_mode;
	saved->hardlink = v_stat.st_nlink;
	saved->inode = v_stat.st_ino;
	saved->uid = v_stat.st_uid;
	saved->gid = v_stat.st_gid;
	saved->rdev = v_stat.st_rdev;
	saved->size = v_stat.st_size;
	saved->has_xattr = listxattr(fullpath, NULL, 0, XATTR_NOFOLLOW);
	if ((acl = acl_get_link_np(fullpath, ACL_TYPE_EXTENDED)) != NULL)
	{
		saved->has_acl = 1;
		acl_free(acl);
	}
}

int				ft_mstat_save(char *path, struct dirent *dir, t_mstat *saved)
{
	char			*fullpath;
	struct stat		v_stat;
	struct timespec	v_timespec;

	ft_strcpy(saved->name, dir->d_name);
	saved->namelen = dir->d_namlen;
	saved->folder = ft_strnew(ft_strlen(path));
	ft_strcpy(saved->folder, path);
	if ((fullpath = ft_fuse_chain(path, dir->d_name)) == NULL)
		return (-1);
	if (lstat(fullpath, &v_stat) == -1)
	{
		ft_strdel(&fullpath);
		return (0);
	}
	ft_mstat_save_part2(saved, fullpath, v_stat);
	v_timespec = v_stat.st_mtimespec;
	saved->mod_time = v_timespec.tv_sec;
	ft_strdel(&fullpath);
	return (1);
}
