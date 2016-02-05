/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_l_mode_right_special_bit_set_u          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 11:48:31 by cledant           #+#    #+#             */
/*   Updated: 2016/01/16 15:23:52 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

int		ft_display_l_mode_right_special_bit_set_user(mode_t set)
{
	if ((set & 0007000) == 0004000)
		return (1);
	else if ((set & 0007000) == 0005000)
		return (1);
	else if ((set & 0007000) == 0006000)
		return (1);
	else if ((set & 0007000) == 0007000)
		return (1);
	else
		return (0);
}
