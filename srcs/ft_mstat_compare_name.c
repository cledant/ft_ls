/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mstat_compare_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 11:37:43 by cledant           #+#    #+#             */
/*   Updated: 2016/01/06 15:38:44 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

int		ft_mstat_compare_name(void *s1, void *s2)
{
	t_mstat		*m_s1;
	t_mstat		*m_s2;

	m_s1 = s1;
	m_s2 = s2;
	return (ft_strcmp(m_s1->name, m_s2->name));
}
