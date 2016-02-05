/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_seek_mod_time.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 17:40:45 by cledant           #+#    #+#             */
/*   Updated: 2016/01/17 13:16:15 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

time_t	ft_seek_mod_time(char *path)
{
	struct stat			v_stat;
	struct timespec		v_timespec;

	if (lstat(path, &v_stat) == -1)
	{
		ft_putstr_fd("ls: ", 2);
		perror(path);
		return (0);
	}
	v_timespec = v_stat.st_mtimespec;
	return (v_timespec.tv_sec);
}
