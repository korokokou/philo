/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbinder <mbinder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:29:17 by mbinder           #+#    #+#             */
/*   Updated: 2015/01/21 19:11:41 by mbinder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*p;

	p = s;
	while (n != 0)
	{
		if ((unsigned char)*p == (unsigned char)c)
		{
			return ((void*)p);
		}
		p++;
		n--;
	}
	return (NULL);
}
