/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mstat_is_content_link_a_dir.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 13:02:10 by cledant           #+#    #+#             */
/*   Updated: 2016/01/16 16:19:15 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

int		ft_mstat_is_content_link_a_dir(t_mstat *v_stat)
{
	mode_t			cpy;
	struct stat		v_link;

	cpy = v_stat->mode;
	cpy = cpy >> 4 * 3;
	cpy = cpy << 4 * 3;
	if (cpy == 0120000)
	{
		if (stat(v_stat->name, &v_link) == -1)
			return (2);
		if ((v_link.st_mode & 0170000) == 0040000)
			return (1);
		else
			return (0);
	}
	else
		return (0);
}
