/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:19:24 by cledant           #+#    #+#             */
/*   Updated: 2016/01/11 15:46:40 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strcmp_nchar(const char *s1, const char *s2, size_t n)
{
	int		result;
	size_t	counter;

	counter = 1;
	result = 0;
	if (n == 0)
		return (0);
	while (counter < n)
	{
		if (*s1 == '\0')
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		s1++;
	}
	result = *(unsigned char *)s1 - *(unsigned char *)s2;
	return (result);
}
