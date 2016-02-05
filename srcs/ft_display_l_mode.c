/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_l_mode.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 08:43:28 by cledant           #+#    #+#             */
/*   Updated: 2016/01/16 17:55:55 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

void			ft_display_l_mode(t_mstat *stat)
{
	ft_display_l_mode_type(stat->mode);
	ft_display_l_mode_user(stat->mode);
	ft_display_l_mode_group(stat->mode);
	ft_display_l_mode_other(stat->mode);
	if (stat->has_xattr > 0)
		ft_putchar('@');
	else
	{
		if (stat->has_acl > 0)
			ft_putchar('+');
		else
			ft_putchar(' ');
	}
}
