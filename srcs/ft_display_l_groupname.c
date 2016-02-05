/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_l_groupname.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 12:37:43 by cledant           #+#    #+#             */
/*   Updated: 2016/01/17 16:10:19 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

void	ft_display_l_groupname(gid_t gid)
{
	struct group	*grp;

	if ((grp = getgrgid(gid)) == NULL)
	{
		ft_putnbr(gid);
		return ;
	}
	else
	{
		ft_putstr(grp->gr_name);
		return ;
	}
}
