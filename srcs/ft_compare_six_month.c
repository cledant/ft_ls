/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compare_six_month.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 15:14:55 by cledant           #+#    #+#             */
/*   Updated: 2016/01/13 19:37:00 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

int				ft_compare_six_month(time_t s1, time_t s2, int flag)
{
	if (s1 - s2 > 0)
		return (0);
	else
	{
		if ((ft_abs(s1 - s2) < (3600 * 24 * 182)) && flag == 1)
			return (1);
		else if ((ft_abs(s1 - s2) < (3600 * 24 * 181)) && flag == 0)
			return (1);
		else
			return (0);
	}
}
