/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_l_time.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 14:14:37 by cledant           #+#    #+#             */
/*   Updated: 2016/01/16 15:30:43 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

static void		ft_internal_display_year(char *time, int flag)
{
	char	*cpy_str;

	cpy_str = time + 20;
	ft_putstrn(time + 3, 7);
	if (flag == 1)
		ft_putchar(' ');
	else
		ft_putstr("  ");
	while (*cpy_str != '\n')
	{
		if (*cpy_str == ' ')
			cpy_str++;
		else
			ft_putchar(*cpy_str);
		cpy_str++;
	}
	ft_putchar(' ');
}

static void		ft_internal_display_time(char *time)
{
	ft_putstrn(time + 3, 13);
	ft_putchar(' ');
}

void			ft_display_l_time(time_t v_time)
{
	char	*s_time;
	char	*s_current_time;
	char	*tmp;
	time_t	current_time;

	current_time = 0;
	s_time = ft_strnew(80);
	s_current_time = ft_strnew(80);
	if ((current_time = time(&current_time)) == -1)
		return ;
	if ((tmp = ctime(&current_time)) == NULL)
		return ;
	ft_strncpy(s_current_time, tmp, 80);
	if ((tmp = ctime(&v_time)) == NULL)
		return ;
	ft_strncpy(s_time, tmp, 80);
	if (ft_compare_six_month(v_time, current_time,
				ft_is_year_leapyear(ft_atoi(s_current_time + 20))) == 0)
		ft_internal_display_year(s_time, ft_compare_six_month(v_time,
			current_time, ft_is_year_leapyear(ft_atoi(s_current_time + 20))));
	else
		ft_internal_display_time(s_time);
	ft_strdel(&s_time);
	ft_strdel(&s_current_time);
}
