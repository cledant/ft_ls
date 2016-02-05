/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lastchar_is_slash.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 15:31:32 by cledant           #+#    #+#             */
/*   Updated: 2016/01/11 16:08:37 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

int		ft_lastchar_is_slash(char *path)
{
	if (ft_strlen(path) <= 1)
		return (0);
	if (ft_strcmp_nchar(path, "/", ft_strlen(path)) == 0)
		return (1);
	return (0);
}
