/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdahan <sdahan@gmail.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/16 20:36:37 by sdahan            #+#    #+#             */
/*   Updated: 2017/05/18 15:43:28 by sdahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strjoinf(char **s1, char const *s2)
{
	char		*join;

	if (!*s1)
		*s1 = ft_strnew(1);
	if ((join = ft_strnew(ft_strlen(*s1) + ft_strlen(s2))))
	{
		join = ft_strcpy(join, *s1);
		join = ft_strcat(join, s2);
		ft_memdel((void**)s1);
	}
	return (join);
}
