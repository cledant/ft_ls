/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mstat_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 09:55:02 by cledant           #+#    #+#             */
/*   Updated: 2016/01/05 15:19:26 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

void		ft_mstat_del(void *del)
{
	t_mstat *ptr_del;

	ptr_del = del;
	ft_strdel(&(ptr_del->name));
	free(del);
	del = NULL;
}
