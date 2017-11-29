/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbinder <mbinder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:31:59 by mbinder           #+#    #+#             */
/*   Updated: 2013/11/26 22:52:22 by mbinder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	char	*save;
	char	*save2;

	if (s2[0] == '\0')
		return ((char*)s1);
	save2 = (char*)s2;
	while (*s1)
	{
		if (*s1 == *s2)
		{
			save = (char*)s1;
			while (*s1 && *s1 == *s2)
			{
				s1++;
				s2++;
			}
			if (*s2 == '\0')
				return (save);
			s1 = (char*)save;
			s2 = (char*)save2;
		}
		s1++;
	}
	return (NULL);
}
