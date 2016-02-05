/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_l_symlink.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 13:01:52 by cledant           #+#    #+#             */
/*   Updated: 2016/01/16 18:41:37 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"
#include <unistd.h>

static int	ft_display_l_symlink_part2(char *tmp, char *buff)
{
	int		ret;

	ret = 1;
	if ((ret = readlink(tmp, buff, 1024)) == -1)
	{
		perror("ls");
		ft_strdel(&tmp);
		ft_strdel(&buff);
		return (0);
	}
	if (ret > 1024)
	{
		ft_strdel(&buff);
		buff = ft_strnew(ret);
		if ((ret = readlink(tmp, buff, ret)) == -1)
		{
			perror("ls");
			ft_strdel(&tmp);
			ft_strdel(&buff);
			return (0);
		}
	}
	return (1);
}

void		ft_display_l_symlink(char *folder, char *name)
{
	char			*tmp;
	char			*buff;

	if (*folder == '\0')
		tmp = ft_strjoin(name, "");
	else
		tmp = ft_fuse_chain(folder, name);
	buff = ft_strnew(1024);
	if (ft_display_l_symlink_part2(tmp, buff) == -1)
		return ;
	ft_putstr(name);
	ft_putstr(" -> ");
	ft_putendl(buff);
	ft_strdel(&tmp);
	ft_strdel(&buff);
}
