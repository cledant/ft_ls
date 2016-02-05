/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linfo_btree_compare_size.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 18:17:19 by cledant           #+#    #+#             */
/*   Updated: 2016/01/16 19:04:26 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

static void		ft_linfo_btree_compare_size_part3(t_linfo *l_stat,
					t_mstat *s_root)
{
	if (s_root->mod_time > l_stat->mode_time)
		l_stat->mode_time = s_root->mod_time;
	if ((s_root->mode & 0170000) == 0020000 ||
			(s_root->mode & 0170000) == 004000)
	{
		if (l_stat->majorlen < ft_return_major_size(s_root->rdev))
			l_stat->majorlen = ft_return_major_size(s_root->rdev);
		if (l_stat->minorlen < ft_return_minor_size(s_root->rdev))
			l_stat->minorlen = ft_return_minor_size(s_root->rdev);
	}
}

static void		ft_linfo_btree_compare_size_part2_5(t_linfo *l_stat,
					t_mstat *s_root)
{
	struct passwd	*pw;
	char			*tmp;

	if ((pw = getpwuid(s_root->uid)) == NULL)
	{
		tmp = ft_itoa(s_root->uid);
		if (ft_strlen(tmp) > l_stat->uidlen)
			l_stat->uidlen = ft_strlen(tmp);
		ft_strdel(&tmp);
	}
	else
	{
		if (ft_strlen(pw->pw_name) > l_stat->uidlen)
			l_stat->uidlen = ft_strlen(pw->pw_name);
	}
}

static void		ft_linfo_btree_compare_size_part2(t_linfo *l_stat,
					t_mstat *s_root)
{
	struct group	*gpw;
	char			*tmp;

	if ((gpw = getgrgid(s_root->gid)) == NULL)
	{
		tmp = ft_itoa(s_root->gid);
		if (ft_strlen(tmp) > l_stat->gidlen)
			l_stat->gidlen = ft_strlen(tmp);
		ft_strdel(&tmp);
	}
	else
	{
		if (ft_strlen(gpw->gr_name) > l_stat->gidlen)
			l_stat->gidlen = ft_strlen(gpw->gr_name);
	}
}

int				ft_linfo_btree_compare_size(t_btree *root, t_linfo *l_stat)
{
	t_mstat			*s_root;
	char			*tmp;

	s_root = root->content;
	if (s_root->namelen > l_stat->namelen)
		l_stat->namelen = s_root->namelen;
	tmp = ft_itoa(s_root->dev);
	if (ft_strlen(tmp) > l_stat->devlen)
		l_stat->devlen = ft_strlen(tmp);
	ft_strdel(&tmp);
	tmp = ft_itoa(s_root->hardlink);
	if (ft_strlen(tmp) > l_stat->hardlinklen)
		l_stat->hardlinklen = ft_strlen(tmp);
	ft_strdel(&tmp);
	tmp = ft_itoa(s_root->size);
	if (ft_strlen(tmp) > l_stat->sizelen)
		l_stat->sizelen = ft_strlen(tmp);
	ft_strdel(&tmp);
	ft_linfo_btree_compare_size_part2(l_stat, s_root);
	ft_linfo_btree_compare_size_part2_5(l_stat, s_root);
	ft_linfo_btree_compare_size_part3(l_stat, s_root);
	return (0);
}
