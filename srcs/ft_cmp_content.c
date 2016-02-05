/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmp_content.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 09:53:21 by cledant           #+#    #+#             */
/*   Updated: 2016/01/17 09:55:54 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

int		ft_cmp_content(void *s1, void *s2)
{
	t_ssort		*c_s1;
	t_ssort		*c_s2;

	c_s1 = s1;
	c_s2 = s2;
	return (ft_strcmp(c_s1->name, c_s2->name));
}
