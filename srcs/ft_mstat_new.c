/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mstat_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 09:57:04 by cledant           #+#    #+#             */
/*   Updated: 2016/01/16 17:46:51 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

static void	ft_mstat_new_part2(t_mstat *new)
{
	new->dev = 0;
	new->hardlink = 0;
	new->uid = 0;
	new->gid = 0;
	new->rdev = 0;
	new->mod_time = 0;
	new->size = 0;
	new->has_xattr = 0;
	new->has_acl = 0;
	new->folder = NULL;
}

t_mstat		*ft_mstat_new(uint16_t namelen)
{
	t_mstat		*new;

	new = (t_mstat *)malloc(sizeof(t_mstat));
	if (new == NULL)
		return (NULL);
	else
	{
		new->inode = 0;
		new->mode = 0;
		new->namelen = namelen;
		if ((new->name = ft_strnew(namelen)) == NULL)
		{
			ft_memdel((void **)&new);
			return (NULL);
		}
	}
	ft_mstat_new_part2(new);
	return (new);
}
