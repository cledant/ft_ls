/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_title_cap_r.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 14:21:18 by cledant           #+#    #+#             */
/*   Updated: 2016/01/11 13:40:19 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_title_cap_r(char *path)
{
	char	*new;

	if (ft_strncmp(path, "./", 2) == 0 || ft_strncmp(path, "/", 1) == 0)
	{
		new = ft_strnew(ft_strlen(path) + 1);
		ft_strcat(new, path);
		ft_strcat(new, ":");
	}
	else
	{
		new = ft_strnew(ft_strlen(path) + 3);
		ft_strcat(new, "./");
		ft_strcat(new, path);
		ft_strcat(new, ":");
	}
	return (new);
}
