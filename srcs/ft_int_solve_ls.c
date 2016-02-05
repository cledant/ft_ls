/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 14:11:44 by cledant           #+#    #+#             */
/*   Updated: 2016/01/17 11:08:16 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

static t_btree		*ft_solve_ls_p1(char **argv, int i, int skip)
{
	t_ssort		*sort_arg;
	t_btree		*root;

	if ((sort_arg = ft_ssort_init(argv[i + skip])) == NULL)
	{
		ft_putstr_fd("ls :", 2);
		perror(argv[i + skip]);
		return (NULL);
	}
	if ((root = ft_btree_new(NULL, 0)) == NULL)
	{
		ft_putstr_fd("ls :", 2);
		perror(argv[i + skip]);
		ft_strdel(&(sort_arg->name));
		ft_memdel((void **)&sort_arg);
		return (NULL);
	}
	root->content = sort_arg;
	return (root);
}

static t_btree		*ft_solve_ls_p2(t_btree *root, char **argv, int all,
						t_option *opt)
{
	t_ssort		*sort_arg;
	t_btree		*new;

	if ((sort_arg = ft_ssort_init(argv[all])) == NULL)
	{
		ft_putstr_fd("ls :", 2);
		perror(argv[all]);
		ft_btree_del_all_0_size_node_other(&root);
		return (NULL);
	}
	if ((new = ft_btree_new(NULL, 0)) == NULL)
	{
		ft_putstr_fd("ls :", 2);
		perror(argv[all]);
		ft_btree_del_all_0_size_node_other(&root);
		ft_strdel(&(sort_arg->name));
		ft_memdel((void **)&sort_arg);
		return (NULL);
	}
	new->content = sort_arg;
	if (opt->sort == 0)
		ft_btree_add_node(root, new, &ft_cmp_content);
	else
		ft_btree_add_node(root, new, &ft_cmp_content_time);
	return (root);
}

int					ft_int_solve_ls(char **argv, int argc, int skip,
						t_option *opt)
{
	int			i;
	int			flag[2];
	t_btree		*root;

	flag[0] = 0;
	flag[1] = 0;
	i = 1;
	if ((root = ft_solve_ls_p1(argv, i, skip)) == NULL)
		return (1);
	i++;
	while (i + skip < argc)
	{
		flag[0] = 1;
		if ((root = ft_solve_ls_p2(root, argv, i + skip, opt)) == NULL)
			return (1);
		i++;
	}
	ft_put_to_screen(root, opt, flag[0], &flag[1]);
	ft_btree_del_all_node(&root);
	return (0);
}
