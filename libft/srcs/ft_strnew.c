/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbinder <mbinder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 21:57:24 by mbinder           #+#    #+#             */
/*   Updated: 2013/11/30 15:02:06 by mbinder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*s;
	char	*save;

	s = (char*)malloc(sizeof(*s) * (size + 1));
	save = s;
	if (s)
	{
		while (size + 1 > 0)
		{
			*s = '\0';
			s++;
			size--;
		}
	}
	return (save);
}
