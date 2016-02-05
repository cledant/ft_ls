/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_l_major.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 13:40:15 by cledant           #+#    #+#             */
/*   Updated: 2016/01/09 08:54:33 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

void		ft_display_l_major(dev_t rdev)
{
	dev_t	val;

	val = rdev;
	val = val >> 24;
	ft_putnbr(val);
}
