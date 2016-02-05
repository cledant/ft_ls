/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return_major_size.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 10:30:41 by cledant           #+#    #+#             */
/*   Updated: 2016/01/16 15:37:12 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

size_t		ft_return_major_size(dev_t rdev)
{
	dev_t	val;

	val = rdev;
	val = val >> 24;
	return (ft_strlen(ft_itoa(val)));
}
