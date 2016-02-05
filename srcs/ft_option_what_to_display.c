/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_what_to_display.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 09:49:40 by cledant           #+#    #+#             */
/*   Updated: 2016/01/16 17:21:00 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

static void		ft_option_what_to_display_part2(t_btree *root, t_option *opt)
{
	t_linfo		pad;

	if (opt->hidden == 0 && opt->detail == 1 && opt->reverse == 0)
	{
		ft_linfo_init(&pad);
		ft_btree_linfo(root, opt, &pad);
		ft_btree_linfo_apply_infix(root, &pad, opt);
	}
	else if (opt->hidden == 1 && opt->detail == 1 && opt->reverse == 0)
	{
		ft_linfo_init(&pad);
		ft_btree_linfo(root, opt, &pad);
		ft_btree_linfo_apply_infix(root, &pad, opt);
	}
	else if (opt->hidden == 1 && opt->detail == 1 && opt->reverse == 1)
	{
		ft_linfo_init(&pad);
		ft_btree_linfo(root, opt, &pad);
		ft_btree_linfo_apply_reverse_infix(root, &pad, opt);
	}
	else if (opt->hidden == 1 && opt->detail == 0 && opt->reverse == 1)
		ft_btree_apply_reverse_infix(root, &ft_display_no_dot);
	else
		ft_btree_apply_infix(root, &ft_display_no_dot);
}

void			ft_option_what_to_display(t_btree *root, t_option *opt,
					t_linfo *linfo)
{
	t_linfo		pad;

	if (root->right == NULL && root->left == NULL)
	{
		if (opt->detail == 0)
			ft_display_all(root->content);
		else if (opt->detail == 1)
			ft_display_l_all(root->content, linfo);
	}
	else
	{
		if (opt->hidden == 0 && opt->detail == 0 && opt->reverse == 0)
			ft_btree_apply_infix(root, &ft_display_all);
		else if (opt->hidden == 0 && opt->detail == 0 && opt->reverse == 1)
			ft_btree_apply_reverse_infix(root, &ft_display_all);
		else if (opt->hidden == 0 && opt->detail == 1 && opt->reverse == 1)
		{
			ft_linfo_init(&pad);
			ft_btree_linfo(root, opt, &pad);
			ft_btree_linfo_apply_reverse_infix(root, &pad, opt);
		}
		else
			ft_option_what_to_display_part2(root, opt);
	}
}
