/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbinder <mbinder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 23:32:22 by mbinder           #+#    #+#             */
/*   Updated: 2015/01/21 19:36:56 by mbinder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*t;
	char	*save;
	size_t	len;

	t = NULL;
	save = NULL;
	if (s && f)
	{
		len = ft_strlen(s) + 1;
		t = (char*)malloc(sizeof(*t) * len);
		save = t;
	}
	if (t && f)
	{
		while (*s)
		{
			*t = f(*s);
			t++;
			s++;
		}
		*t = '\0';
	}
	return (save);
}
