/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbinder <mbinder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 22:38:53 by mbinder           #+#    #+#             */
/*   Updated: 2015/01/21 23:04:05 by mbinder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		len;
	char	*str;

	str = NULL;
	if (s)
	{
		while (*s && (*s == ' ' || *s == '\n' || *s == '\t'))
			s++;
		len = ft_strlen(s);
		while (*s && (*(s + len) == ' ' || *(s + len) == '\n' ||
					*(s + len) == '\t' || *(s + len) == '\0'))
			len--;
		if ((str = ft_strnew(len)))
		{
			str = ft_strncpy(str, s, len + 1);
			str[len + 1] = '\0';
		}
	}
	return (str);
}
