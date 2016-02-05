/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mstat_is_content_null.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 13:39:08 by cledant           #+#    #+#             */
/*   Updated: 2016/01/12 13:37:14 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

int		ft_mstat_is_content_null(t_mstat *stat)
{
	mode_t	cpy;

	cpy = stat->mode;
	cpy = cpy >> 4 * 3;
	cpy = cpy << 4 * 3;
	if (cpy == 0000000)
		return (1);
	else
		return (0);
}
