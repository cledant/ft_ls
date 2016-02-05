/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 15:21:50 by cledant           #+#    #+#             */
/*   Updated: 2016/01/14 10:02:07 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

void	ft_display_all(void *content)
{
	t_mstat		*stat;

	stat = content;
	if (ft_mstat_is_content_null(stat) == 0)
		ft_putendl(stat->name);
	else
	{
		ft_putstr_fd("ls :", 2);
		perror(stat->name);
		return ;
	}
}
