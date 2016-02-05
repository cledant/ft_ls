/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_l_mode_right_special_bit_set_o          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 11:30:38 by cledant           #+#    #+#             */
/*   Updated: 2016/01/16 15:24:09 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

int		ft_display_l_mode_right_special_bit_set_other(mode_t set)
{
	if ((set & 0007000) == 0001000)
		return (1);
	else if ((set & 0007000) == 0003000)
		return (1);
	else if ((set & 0007000) == 0005000)
		return (1);
	else if ((set & 0007000) == 0007000)
		return (1);
	else
		return (0);
}
