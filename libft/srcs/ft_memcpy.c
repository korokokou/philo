/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbinder <mbinder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:25:11 by mbinder           #+#    #+#             */
/*   Updated: 2015/01/20 16:34:14 by mbinder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*d1;
	const char	*s1;

	d1 = dst;
	s1 = src;
	while (n != 0)
	{
		*d1 = *s1;
		d1++;
		s1++;
		n--;
	}
	return (dst);
}
