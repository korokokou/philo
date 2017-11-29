/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbinder <mbinder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 18:02:55 by mbinder           #+#    #+#             */
/*   Updated: 2013/11/28 19:49:22 by mbinder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	s;
	size_t	d;

	s = ft_strlen(src);
	d = ft_strlen(dst);
	if (d > size)
		return (s + size);
	s = d + s;
	while (*src && d + 1 < size)
	{
		dst[d] = *src;
		d++;
		src++;
	}
	dst[d] = '\0';
	return (s);
}
