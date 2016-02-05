/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argv_is_opt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 11:37:16 by cledant           #+#    #+#             */
/*   Updated: 2016/01/11 21:09:49 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

int		ft_argv_is_opt(char *s)
{
	if (ft_strcmp(s, "--") == 0)
		return (0);
	if (ft_strncmp(s, "-", 1) == 0)
	{
		if (ft_strlen(s) <= 1)
			return (0);
		else
			return (1);
	}
	return (0);
}
