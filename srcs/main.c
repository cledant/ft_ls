/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 14:11:44 by cledant           #+#    #+#             */
/*   Updated: 2016/01/17 14:22:54 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

static int		main_part1(int argc, char **argv)
{
	int i;
	int	valid;

	i = 1;
	valid = 0;
	while (i < argc && (valid = ft_argv_is_opt_valid(argv[i])) == 1)
		i++;
	if (argc != 1 && valid == 0)
		return (0);
	while (i < argc)
	{
		if (*argv[i] == '\0')
		{
			ft_putendl_fd("ls: fts_open: No such file or directory", 2);
			return (1);
		}
		i++;
	}
	return (0);
}

static int		main_part2(char **argv, t_option *opt)
{
	int		error;

	error = 0;
	if (ft_argv_is_opt(argv[1]) == 1)
	{
		if (ft_option_fill_struct(argv[1], opt) == 0)
			return (1);
		error = ft_option_ls(".", opt, NULL);
	}
	else if (ft_strcmp(argv[1], "--") == 0)
		error = ft_option_ls(".", opt, NULL);
	else
		error = ft_option_ls(argv[1], opt, NULL);
	return (error);
}

static int		main_part3_5(char **argv, int argc, t_option *opt, int i)
{
	int	error;

	error = 0;
	if (i == argc)
		error = ft_option_ls(".", opt, NULL);
	else if (i == argc - 1 && ft_strcmp(argv[i], "--") == 0)
	{
		ft_bzero(argv[i], 2);
		ft_strcpy(argv[i], ".");
		error = ft_option_ls(".", opt, NULL);
	}
	else if (i + 1 < argc && ft_strcmp(argv[i], "--") == 0)
		error = ft_int_solve_ls(argv, argc, i, opt);
	else
		error = ft_int_solve_ls(argv, argc, i - 1, opt);
	return (error);
}

static int		main_part3(char **argv, int argc, t_option *opt, int i)
{
	int	error;

	error = 0;
	if (ft_strcmp(argv[1], "--") == 0)
		error = ft_int_solve_ls(argv, argc, 1, opt);
	else if (ft_argv_is_opt(argv[i]) == 1)
	{
		while (i < argc && ft_argv_is_opt(argv[i]) == 1)
		{
			if (ft_option_fill_struct(argv[i], opt) == 0)
				return (1);
			i++;
		}
		error = main_part3_5(argv, argc, opt, i);
	}
	else
		error = ft_int_solve_ls(argv, argc, 0, opt);
	return (error);
}

int				main(int argc, char **argv)
{
	t_option	opt;
	int			error;
	int			i;

	i = 1;
	error = 0;
	ft_option_init(&opt);
	if (main_part1(argc, argv) == 1)
		return (1);
	if (argc == 1)
	{
		error = ft_option_ls(".", &opt, NULL);
		return (error);
	}
	else if (argc == 2)
	{
		if ((error == main_part2(argv, &opt)) == 1)
			return (1);
	}
	else if (argc > 2)
	{
		if ((error == main_part3(argv, argc, &opt, i)) == 1)
			return (1);
	}
	return (error);
}
