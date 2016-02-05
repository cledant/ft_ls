/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmp_content_time.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 09:55:11 by cledant           #+#    #+#             */
/*   Updated: 2016/01/17 09:55:43 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

int		ft_cmp_content_time(void *s1, void *s2)
{
	t_ssort		*c_s1;
	t_ssort		*c_s2;

	c_s1 = s1;
	c_s2 = s2;
	if (c_s2->mod_time - c_s1->mod_time == 0)
		return (ft_strcmp(c_s1->name, c_s2->name));
	else
		return (c_s2->mod_time - c_s1->mod_time);
}
