/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_l_offset_user.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 09:57:46 by cledant           #+#    #+#             */
/*   Updated: 2016/01/13 10:02:46 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

size_t		ft_display_l_offset_user(uid_t uid, size_t maxlen)
{
	struct passwd	*user;

	if ((user = getpwuid(uid)) == NULL)
	{
		return (maxlen - ft_strlen(ft_itoa(uid)));
	}
	else
	{
		return (maxlen - ft_strlen(user->pw_name));
	}
}
