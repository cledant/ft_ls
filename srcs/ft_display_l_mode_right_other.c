/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_l_mode_right_other.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 20:27:08 by cledant           #+#    #+#             */
/*   Updated: 2016/01/16 18:07:55 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

void	ft_display_l_mode_right_other_part2(mode_t right)
{
	if ((right & 0000007) == 000000)
		ft_putstr("---");
	else if ((right & 0000007) == 000001)
		ft_putstr("--x");
	else if ((right & 0000007) == 000002)
		ft_putstr("-w-");
	else if ((right & 0000007) == 000003)
		ft_putstr("-wx");
	else if ((right & 0000007) == 000004)
		ft_putstr("r--");
	else if ((right & 0000007) == 000005)
		ft_putstr("r-x");
	else if ((right & 0000007) == 000006)
		ft_putstr("rw-");
	else if ((right & 0000007) == 000007)
		ft_putstr("rwx");
}

void	ft_display_l_mode_right_other(mode_t right, mode_t set)
{
	if (ft_display_l_mode_right_special_bit_set_other(set) == 1)
	{
		if ((right & 0000007) == 000000)
			ft_putstr("--T");
		else if ((right & 0000007) == 000001)
			ft_putstr("--t");
		else if ((right & 0000007) == 000002)
			ft_putstr("-wT");
		else if ((right & 0000007) == 000003)
			ft_putstr("-wt");
		else if ((right & 0000007) == 000004)
			ft_putstr("r-T");
		else if ((right & 0000007) == 000005)
			ft_putstr("r-t");
		else if ((right & 0000007) == 000006)
			ft_putstr("rwT");
		else if ((right & 0000007) == 000007)
			ft_putstr("rwt");
	}
	else
		ft_display_l_mode_right_other_part2(right);
}
