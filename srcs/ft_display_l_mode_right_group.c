/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_l_mode_right_group.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 20:33:12 by cledant           #+#    #+#             */
/*   Updated: 2016/01/16 18:08:18 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

static void		ft_display_l_mode_right_group_part2(mode_t right)
{
	if ((right & 0000070) == 000000)
		ft_putstr("---");
	else if ((right & 0000070) == 000010)
		ft_putstr("--x");
	else if ((right & 0000070) == 000020)
		ft_putstr("-w-");
	else if ((right & 0000070) == 000030)
		ft_putstr("-wx");
	else if ((right & 0000070) == 000040)
		ft_putstr("r--");
	else if ((right & 0000070) == 000050)
		ft_putstr("r-x");
	else if ((right & 0000070) == 000060)
		ft_putstr("rw-");
	else if ((right & 0000070) == 000070)
		ft_putstr("rwx");
}

void			ft_display_l_mode_right_group(mode_t right, mode_t set)
{
	if (ft_display_l_mode_right_special_bit_set_group(set) == 1)
	{
		if ((right & 0000070) == 000000)
			ft_putstr("--S");
		else if ((right & 0000070) == 000010)
			ft_putstr("--s");
		else if ((right & 0000070) == 000020)
			ft_putstr("-wS");
		else if ((right & 0000070) == 000030)
			ft_putstr("-ws");
		else if ((right & 0000070) == 000040)
			ft_putstr("r-S");
		else if ((right & 0000070) == 000050)
			ft_putstr("r-s");
		else if ((right & 0000070) == 000060)
			ft_putstr("rwS");
		else if ((right & 0000070) == 000070)
			ft_putstr("rws");
	}
	else
		ft_display_l_mode_right_group_part2(right);
}
