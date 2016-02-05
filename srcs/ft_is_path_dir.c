/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_path_dir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 21:14:24 by cledant           #+#    #+#             */
/*   Updated: 2016/01/14 13:15:18 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

int		ft_is_path_dir(char *path)
{
	struct stat		v_stat;

	if (lstat(path, &v_stat) == -1)
		return (2);
	if ((v_stat.st_mode & 0170000) == 0040000)
		return (1);
	else
		return (0);
}
