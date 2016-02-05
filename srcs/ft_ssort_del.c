/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssort_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 16:39:35 by cledant           #+#    #+#             */
/*   Updated: 2016/01/12 16:40:06 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

void		ft_ssort_del(void *del)
{
	t_ssort		*ptr_del;

	ptr_del = del;
	ft_strdel(&(ptr_del->name));
	free(del);
	del = NULL;
}
