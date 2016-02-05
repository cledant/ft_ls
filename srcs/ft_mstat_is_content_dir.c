/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mstat_is_content_dir.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 13:39:08 by cledant           #+#    #+#             */
/*   Updated: 2016/01/07 10:47:49 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

int		ft_mstat_is_content_dir(t_mstat *stat)
{
	mode_t	cpy;

	cpy = stat->mode;
	cpy = cpy >> 4 * 3;
	cpy = cpy << 4 * 3;
	if (cpy == 0040000)
		return (1);
	else
		return (0);
}
