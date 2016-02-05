/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssort_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 20:55:59 by cledant           #+#    #+#             */
/*   Updated: 2016/01/16 15:38:07 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

t_ssort		*ft_ssort_init(char *arg)
{
	t_ssort		*new;

	if ((new = (t_ssort *)malloc(sizeof(t_ssort))) == NULL)
		return (NULL);
	if ((new->name = ft_strnew(ft_strlen(arg))) == NULL)
	{
		ft_memdel((void **)new);
		return (NULL);
	}
	ft_strcpy(new->name, arg);
	new->is_dir = ft_is_path_dir(new->name);
	new->mod_time = ft_seek_mod_time(new->name);
	return (new);
}
