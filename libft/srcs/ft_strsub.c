/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbinder <mbinder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 00:51:26 by mbinder           #+#    #+#             */
/*   Updated: 2015/01/21 22:11:56 by mbinder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s1;
	int		i;

	i = 0;
	s1 = malloc(sizeof(*s1) * (len + 1));
	if (s1 && s)
	{
		while (len > 0 && s[start])
		{
			s1[i] = ((char*)s)[start];
			i++;
			start++;
			len--;
		}
		s1[i] = '\0';
	}
	return (s1);
}
