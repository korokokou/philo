/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbinder <mbinder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 16:28:36 by mbinder           #+#    #+#             */
/*   Updated: 2015/01/21 18:35:20 by mbinder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_2(char *s, int n, int length)
{
	int		d;
	int		m;
	int		signe;

	d = n;
	signe = 1;
	if (n < 0)
		signe = -1;
	while (d != 0)
	{
		m = (d % 10) * signe;
		*(s + length - 1) = m + '0';
		d = d / 10;
		length--;
	}
	if (n < 0)
		*s = '-';
	if (n == 0)
		*s = 0 + '0';
	return (s);
}

char	*ft_itoa(int n)
{
	int		length;
	int		d;
	char	*s;

	length = 0;
	d = n;
	while (d != 0)
	{
		d = d / 10;
		length++;
	}
	if (n <= 0)
		length++;
	s = ft_strnew(length);
	s = ft_itoa_2(s, n, length);
	return (s);
}
