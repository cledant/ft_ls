/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return_minor_size.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 10:38:42 by cledant           #+#    #+#             */
/*   Updated: 2016/01/16 10:50:45 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

size_t		ft_return_minor_size(dev_t rdev)
{
	dev_t	val;

	val = rdev;
	val = val << 12;
	val = val >> 12;
	return (ft_strlen(ft_itoa(val)));
}
