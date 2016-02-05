/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mstat_compare_time.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 17:55:59 by cledant           #+#    #+#             */
/*   Updated: 2016/01/13 17:15:22 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

int		ft_mstat_compare_time(void *s1, void *s2)
{
	t_mstat		*m_s1;
	t_mstat		*m_s2;

	m_s1 = s1;
	m_s2 = s2;
	if ((m_s2->mod_time - m_s1->mod_time) == 0)
		return (ft_strcmp(m_s1->name, m_s2->name));
	else
		return (m_s2->mod_time - m_s1->mod_time);
}
