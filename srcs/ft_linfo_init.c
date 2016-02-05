/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linfo_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 18:08:51 by cledant           #+#    #+#             */
/*   Updated: 2016/01/16 10:38:02 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

void	ft_linfo_init(t_linfo *new)
{
	new->namelen = 0;
	new->devlen = 0;
	new->hardlinklen = 0;
	new->uidlen = 0;
	new->gidlen = 0;
	new->minorlen = 0;
	new->majorlen = 0;
	new->mode_time = 0;
	new->sizelen = 0;
}
