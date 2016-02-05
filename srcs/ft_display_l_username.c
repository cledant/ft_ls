/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_l_username.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 12:09:29 by cledant           #+#    #+#             */
/*   Updated: 2016/01/17 16:12:06 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

void	ft_display_l_username(uid_t uid)
{
	struct passwd	*user;

	if ((user = getpwuid(uid)) == NULL)
	{
		ft_putnbr(uid);
		return ;
	}
	else
	{
		ft_putstr(user->pw_name);
		return ;
	}
}
