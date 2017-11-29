/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbinder <mbinder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 16:36:31 by mbinder           #+#    #+#             */
/*   Updated: 2015/01/20 17:06:16 by mbinder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*s;
	char	*save;

	s = NULL;
	save = NULL;
	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2) + 1;
		s = (char*)malloc(sizeof(*s) * len);
		save = s;
		if (s)
		{
			ft_strcpy(s, s1);
			ft_strcpy(s + ft_strlen(s1), s2);
		}
	}
	return (save);
}
