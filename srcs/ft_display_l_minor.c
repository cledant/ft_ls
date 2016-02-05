/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_l_minor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 13:45:25 by cledant           #+#    #+#             */
/*   Updated: 2016/01/09 08:49:25 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

void		ft_display_l_minor(dev_t rdev)
{
	dev_t	val;

	val = rdev;
	val = val << 12;
	val = val >> 12;
	ft_putnbr(val);
}
