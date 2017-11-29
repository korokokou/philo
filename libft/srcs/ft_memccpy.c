/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbinder <mbinder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:26:14 by mbinder           #+#    #+#             */
/*   Updated: 2015/01/21 19:10:59 by mbinder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	char		*t1;
	const char	*t2;

	t1 = s1;
	t2 = s2;
	while (n > 0)
	{
		*t1 = *t2;
		if ((unsigned char)*t2 == (unsigned char)c)
		{
			t1++;
			return ((void*)t1);
		}
		t1++;
		t2++;
		n--;
	}
	return (0);
}
