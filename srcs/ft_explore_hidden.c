/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_explore_hidden.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 16:48:10 by cledant           #+#    #+#             */
/*   Updated: 2016/01/11 15:47:41 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

int		ft_explore_hidden(char *path, int hidden)
{
	int	first_is_dot;

	if (ft_strcmp_nchar(path, ".", 1) == 0)
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
