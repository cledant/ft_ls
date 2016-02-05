/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_l_mode_user.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 11:45:48 by cledant           #+#    #+#             */
/*   Updated: 2016/01/08 20:42:13 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

void		ft_display_l_mode_group(mode_t mode)
{
	mode_t	right;
	mode_t	set;

	right = mode;
	set = mode;
	ft_display_l_mode_right_group(right, set);
}
