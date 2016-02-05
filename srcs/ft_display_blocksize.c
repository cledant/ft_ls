/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_blocksize.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 15:29:52 by cledant           #+#    #+#             */
/*   Updated: 2016/01/17 09:06:07 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

static blkcnt_t		ft_display_blocksize_part2(DIR *ptr_dir, int flag,
						char *path, int *disp)
{
	char			*tmp;
	struct dirent	*dir;
	blkcnt_t		count;
	struct stat		v_stat;

	count = 0;
	while ((dir = readdir(ptr_dir)) != NULL)
	{
		if (ft_explore_hidden(dir->d_name, flag) == 1)
		{
			tmp = ft_fuse_chain(path, dir->d_name);
			if (lstat(tmp, &v_stat) == -1)
			{
				closedir(ptr_dir);
				ft_strdel(&tmp);
				return (0);
			}
			count = count + v_stat.st_blocks;
			ft_strdel(&tmp);
			*disp = 1;
		}
	}
	closedir(ptr_dir);
	return (count);
}

void				ft_display_blocksize(char *path, int flag)
{
	DIR				*ptr_dir;
	blkcnt_t		count;
	int				disp;

	disp = 0;
	count = 0;
	if ((ptr_dir = opendir(path)) == NULL)
		return ;
	count = ft_display_blocksize_part2(ptr_dir, flag, path, &disp);
	if (disp != 0)
	{
		ft_putstr("total ");
		ft_putnbrendl(count);
	}
}
