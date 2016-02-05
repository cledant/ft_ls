/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_fill_struct.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 09:57:27 by cledant           #+#    #+#             */
/*   Updated: 2016/01/16 21:34:52 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

static void		ft_print_error(char *s)
{
	ft_putstr_fd("ls: illegal option -- ", 2);
	ft_putchar_fd(*s, 2);
	ft_putendl_fd("", 2);
	ft_putstr_fd("usage: ls [-ABCFGHLOPRSTUW@abcdefgh", 2);
	ft_putendl_fd("iklmnopqrstuwx1] [file ...]", 2);
}

static void		ft_assign_value(char *s, t_option *opt)
{
	if (*s == 'a')
		opt->hidden = 0;
	else if (*s == 'l')
		opt->detail = 1;
	else if (*s == 'R')
		opt->all_dir = 1;
	else if (*s == 'r')
		opt->reverse = 1;
	else if (*s == 't')
		opt->sort = 1;
	else
		opt->other = 1;
}

static int		ft_end(char *seek, char *cpy_seek, char *s)
{
	if (*seek == '\0')
	{
		ft_print_error(s);
		ft_strdel(&cpy_seek);
		return (0);
	}
	ft_strdel(&cpy_seek);
	return (1);
}

int				ft_option_fill_struct(char *s, t_option *opt)
{
	char	*seek;
	char	*cpy_seek;

	if ((seek = ft_strnew(38)) == NULL)
	{
		perror("ls :");
		return (0);
	}
	ft_strcpy(seek, "ABCFGHLOPRSTUW@abcdefghiklmnopqrstuwx1");
	s++;
	cpy_seek = seek;
	while (*seek != '\0' && *s != '\0')
	{
		if (*seek == *s)
		{
			ft_assign_value(s, opt);
			seek = cpy_seek;
			s++;
		}
		seek++;
	}
	return (ft_end(seek, cpy_seek, s));
}
