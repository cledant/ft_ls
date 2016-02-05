/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_l_mode_right.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 11:34:52 by cledant           #+#    #+#             */
/*   Updated: 2016/01/16 18:08:39 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

static void	ft_display_l_mode_right_part2(mode_t right)
{
	if ((right & 0000700) == 000000)
		ft_putstr("---");
	else if ((right & 0000700) == 000100)
		ft_putstr("--x");
	else if ((right & 0000700) == 000200)
		ft_putstr("-w-");
	else if ((right & 0000700) == 000300)
		ft_putstr("-wx");
	else if ((right & 0000700) == 000400)
		ft_putstr("r--");
	else if ((right & 0000700) == 000500)
		ft_putstr("r-x");
	else if ((right & 0000700) == 000600)
		ft_putstr("rw-");
	else if ((right & 0000700) == 000700)
		ft_putstr("rwx");
}

void		ft_display_l_mode_right(mode_t right, mode_t set)
{
	if (ft_display_l_mode_right_special_bit_set_user(set) == 1)
	{
		if ((right & 0000700) == 000000)
			ft_putstr("--S");
		else if ((right & 0000700) == 000100)
			ft_putstr("--s");
		else if ((right & 0000700) == 000200)
			ft_putstr("-wS");
		else if ((right & 0000700) == 000300)
			ft_putstr("-ws");
		else if ((right & 0000700) == 000400)
			ft_putstr("r-S");
		else if ((right & 0000700) == 000500)
			ft_putstr("r-s");
		else if ((right & 0000700) == 000600)
			ft_putstr("rwS");
		else if ((right & 0000700) == 000700)
			ft_putstr("rws");
	}
	else
		ft_display_l_mode_right_part2(right);
}
