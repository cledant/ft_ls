/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fuse_chain.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 13:55:41 by cledant           #+#    #+#             */
/*   Updated: 2016/01/11 13:49:25 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

char	*ft_fuse_chain(char *path, char *name)
{
	int		flag;
	char	*fullpath;

	flag = 0;
	if (ft_strcmp(path, "/") != 0)
		flag = 1;
	if (flag == 1)
		fullpath = ft_strnew(ft_strlen(path) + 1 + ft_strlen(name));
	else
		fullpath = ft_strnew(ft_strlen(path) + ft_strlen(name));
	ft_strcat(fullpath, path);
	if (flag == 1)
		ft_strcat(fullpath, "/");
	ft_strcat(fullpath, name);
	return (fullpath);
}
