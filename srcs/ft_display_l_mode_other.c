/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_l_mode_other.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 11:50:39 by cledant           #+#    #+#             */
/*   Updated: 2016/01/08 20:28:30 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

void		ft_display_l_mode_other(mode_t mode)
{
	mode_t	right;
	mode_t	set;

	right = mode;
	set = mode;
	ft_display_l_mode_right_other(right, set);
}
