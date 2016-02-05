/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argv_is_opt_valid.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 21:42:07 by cledant           #+#    #+#             */
/*   Updated: 2016/01/16 21:48:42 by cledant          ###   ########.fr       */
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

static int		ft_exception(char *s)
{
	if (ft_strncmp(s, "-", 1) != 0)
		return (1);
	if (ft_strcmp(s, "--") == 0)
		return (1);
	return (0);
}

int				ft_argv_is_opt_valid(char *s)
{
	char	*seek;
	char	*cpy_seek;

	if (ft_exception(s) == 1)
		return (2);
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
			seek = cpy_seek;
			s++;
		}
		seek++;
	}
	return (ft_end(seek, cpy_seek, s));
}
