/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbinder <mbinder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:51:26 by mbinder           #+#    #+#             */
/*   Updated: 2015/01/20 16:41:54 by mbinder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	char	*save;

	save = dst;
	while (*src && n > 0)
	{
		*dst = *src;
		dst++;
		src++;
		n--;
	}
	while (n > 0)
	{
		*dst = '\0';
		dst++;
		n--;
	}
	return (save);
}
