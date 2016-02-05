/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mstat_explore_hidden.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 09:47:08 by cledant           #+#    #+#             */
/*   Updated: 2016/01/11 15:48:00 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

int		ft_mstat_explore_hidden(t_mstat *stat, int hidden)
{
	int	first_is_dot;

	if (ft_strcmp_nchar(stat->name, ".", 1) == 0)
		first_is_dot = 1;
	else
		first_is_dot = 0;
	if (first_is_dot == 1 && hidden == 1)
		return (0);
	else if (first_is_dot == 0 && hidden == 1)
		return (1);
	else if (first_is_dot == 1 && hidden == 0)
		return (1);
	else
		return (1);
}
