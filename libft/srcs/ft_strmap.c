/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:17:38 by cledant           #+#    #+#             */
/*   Updated: 2015/12/10 13:36:42 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*fresh;
	char	*cpy_fresh;
	size_t	len;

	len = ft_strlen(s);
	fresh = ft_strnew(len);
	if (fresh == NULL)
		return (fresh);
	cpy_fresh = fresh;
	while (*s != '\0')
	{
		*fresh = (*f)(*s);
		s++;
		fresh++;
	}
	*fresh = '\0';
	return (cpy_fresh);
}
