/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarczyn <lgarczyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:28:10 by mbinder           #+#    #+#             */
/*   Updated: 2017/05/09 15:56:00 by lgarczyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	if (d <= s)
	{
		return (ft_memcpy(dst, src, n));
	}
	d = d + n;
	s = s + n;
	while (n > 0)
	{
		d--;
		s--;
		*d = *s;
		n--;
	}
	return (dst);
}
