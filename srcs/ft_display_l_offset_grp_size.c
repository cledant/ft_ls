/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_l_offset_grp_size.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 10:13:22 by cledant           #+#    #+#             */
/*   Updated: 2016/01/16 15:28:16 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

size_t		ft_display_l_offset_grp_size(gid_t uid, size_t gmaxlen,
				off_t size, size_t smaxlen)
{
	struct group	*grp;

	if ((grp = getgrgid(uid)) == NULL)
	{
		return (gmaxlen - ft_strlen(ft_itoa(uid)) + smaxlen -
					ft_strlen(ft_itoa(size)));
	}
	else
	{
		return (gmaxlen - ft_strlen(grp->gr_name) + smaxlen -
					ft_strlen(ft_itoa(size)));
	}
}
