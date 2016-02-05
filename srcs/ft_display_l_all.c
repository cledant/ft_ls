/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_l_all.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 09:43:31 by cledant           #+#    #+#             */
/*   Updated: 2016/01/17 09:43:33 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"
#include <unistd.h>

static void		ft_disp_l_no_dot_p1(t_mstat *v_stat, t_linfo *pad)
{
	size_t		n;
	size_t		max;

	max = 0;
	n = 0;
	ft_display_l_mode(v_stat);
	ft_putchar(' ');
	while (n < (pad->hardlinklen - ft_strlen(ft_itoa(v_stat->hardlink))))
	{
		ft_putchar(' ');
		n++;
	}
	ft_putnbr(v_stat->hardlink);
	n = 0;
	ft_putchar(' ');
	ft_display_l_username(v_stat->uid);
	max = ft_display_l_offset_user(v_stat->uid, pad->uidlen);
	while (n < max)
	{
		ft_putchar(' ');
		n++;
	}
	ft_putstr("  ");
	ft_display_l_groupname(v_stat->gid);
}

static void		ft_disp_l_no_dot_p2(t_mstat *v_stat, t_linfo *pad)
{
	size_t	n;

	n = 0;
	while (n < (pad->majorlen - ft_return_major_size(v_stat->rdev)))
	{
		ft_putchar(' ');
		n++;
	}
	ft_display_l_major(v_stat->rdev);
	n = 0;
	ft_putstr(", ");
	while (n < (pad->minorlen - ft_return_minor_size(v_stat->rdev)))
	{
		ft_putchar(' ');
		n++;
	}
	ft_display_l_minor(v_stat->rdev);
}

static void		ft_disp_l_no_dot_p1_5(t_mstat *v_stat, t_linfo *pad)
{
	size_t	n;

	n = 0;
	if (ft_mstat_is_content_sp_char(v_stat) == 1 ||
				ft_mstat_is_content_sp_block(v_stat) == 1)
		ft_disp_l_no_dot_p2(v_stat, pad);
	else if (pad->majorlen != 0 && pad->minorlen != 0)
	{
		while (n < ((pad->minorlen + pad->majorlen + 1)))
		{
			ft_putchar(' ');
			n++;
		}
		n = 0;
		ft_putnbr(v_stat->size);
	}
	else
	{
		ft_putstr("  ");
		ft_putnbr(v_stat->size);
	}
	ft_display_l_time(v_stat->mod_time);
}

static int		ft_disp_l_no_dot_p0_5(t_mstat *v_stat)
{
	struct stat	nop;
	char		*fullpath;

	if (ft_mstat_is_content_null(v_stat) == 1)
	{
		if ((fullpath = ft_fuse_chain(v_stat->folder, v_stat->name))
				== NULL)
		{
			ft_putstr_fd("ls :", 2);
			perror(v_stat->name);
			return (0);
		}
		if (lstat(fullpath, &nop) == -1)
		{
			ft_putstr_fd("ls :", 2);
			perror(v_stat->name);
			ft_strdel(&fullpath);
			return (0);
		}
	}
	return (1);
}

void			ft_display_l_all(void *content, t_linfo *pad)
{
	t_mstat		*v_stat;
	size_t		n;
	size_t		max;

	max = 0;
	n = 0;
	v_stat = content;
	if (ft_disp_l_no_dot_p0_5(v_stat) == 0)
		return ;
	ft_disp_l_no_dot_p1(v_stat, pad);
	max = ft_display_l_offset_grp_size(v_stat->gid, pad->gidlen,
		v_stat->size, pad->sizelen);
	while (n < max)
	{
		ft_putchar(' ');
		n++;
	}
	ft_disp_l_no_dot_p1_5(v_stat, pad);
	if (ft_mstat_is_content_link(v_stat) == 1)
		ft_display_l_symlink(v_stat->folder, v_stat->name);
	else
		ft_putendl(v_stat->name);
}
