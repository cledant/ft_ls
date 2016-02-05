/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_l_mode_type.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 11:30:37 by cledant           #+#    #+#             */
/*   Updated: 2016/01/08 17:47:46 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

void	ft_display_l_mode_type(mode_t mode)
{
	mode_t	cpy;

	cpy = mode;
	cpy = cpy >> 4 * 3;
	cpy = cpy << 4 * 3;
	if (cpy == 0010000)
		ft_putchar('p');
	else if (cpy == 0020000)
		ft_putchar('c');
	else if (cpy == 0040000)
		ft_putchar('d');
	else if (cpy == 0060000)
		ft_putchar('b');
	else if (cpy == 0100000)
		ft_putchar('-');
	else if (cpy == 0120000)
		ft_putchar('l');
	else if (cpy == 0140000)
		ft_putchar('s');
	else if (cpy == 0160000)
		ft_putchar('w');
	else
		ft_putchar(' ');
}
