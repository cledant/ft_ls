/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_path_link.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 15:27:43 by cledant           #+#    #+#             */
/*   Updated: 2016/01/11 20:15:03 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

int		ft_is_path_link(char *path)
{
	struct stat		v_stat;

	if (lstat(path, &v_stat) == -1)
		return (2);
	if ((v_stat.st_mode & 0170000) == 0120000)
		return (1);
	else
		return (0);
}
