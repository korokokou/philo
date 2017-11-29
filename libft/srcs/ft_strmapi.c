/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbinder <mbinder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 00:04:43 by mbinder           #+#    #+#             */
/*   Updated: 2015/01/21 19:40:56 by mbinder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*t;
	size_t			len;
	unsigned int	i;

	t = NULL;
	if (s && f)
	{
		len = ft_strlen(s) + 1;
		t = (char*)malloc(sizeof(*t) * len);
	}
	i = -1;
	if (t && f)
	{
		while (s[++i])
			t[i] = f(i, s[i]);
		t[i] = '\0';
	}
	return (t);
}
