/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbinder <mbinder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:32:53 by mbinder           #+#    #+#             */
/*   Updated: 2015/01/21 21:13:57 by mbinder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char	*save;
	char	*save2;
	int		s;

	if (s2[0] == '\0')
		return ((char*)s1);
	save2 = (char*)s2;
	while (*s1 && n > 0)
	{
		s = n;
		save = (char*)s1;
		while (*s1 && *s1 == *s2 && n-- > 0)
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')
			return (save);
		s1 = (char*)save;
		s2 = (char*)save2;
		n = s;
		s1++;
		n--;
	}
	return (NULL);
}
