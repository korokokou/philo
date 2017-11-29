/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbinder <mbinder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:30:29 by mbinder           #+#    #+#             */
/*   Updated: 2013/11/27 19:03:35 by mbinder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	c1;
	unsigned char	c2;

	while (n != 0)
	{
		c1 = *(unsigned char*)s1;
		c2 = *(unsigned char*)s2;
		if (c1 != c2)
			return (c1 - c2);
		s1++;
		s2++;
		n--;
	}
	return (0);
}
