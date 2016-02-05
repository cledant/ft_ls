/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 08:47:26 by cledant           #+#    #+#             */
/*   Updated: 2016/01/12 15:40:02 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

void	ft_option_init(t_option *opt)
{
	opt->hidden = 1;
	opt->sort = 0;
	opt->detail = 0;
	opt->reverse = 0;
	opt->all_dir = 0;
	opt->other = 0;
}
