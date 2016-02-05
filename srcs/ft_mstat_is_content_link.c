/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mstat_is_content_link.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 17:13:15 by cledant           #+#    #+#             */
/*   Updated: 2016/01/08 17:14:34 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

int		ft_mstat_is_content_link(t_mstat *stat)
{
	mode_t	cpy;

	cpy = stat->mode;
	cpy = cpy >> 4 * 3;
	cpy = cpy << 4 * 3;
	if (cpy == 0120000)
		return (1);
	else
		return (0);
}
