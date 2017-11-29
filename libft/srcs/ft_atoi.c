/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarczyn <lgarczyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 10:35:38 by mbinder           #+#    #+#             */
/*   Updated: 2017/06/24 17:43:25 by sdahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_atoi(const char *str)
{
	int i;
	int m;

	if (!str)
		return (0);
	i = 0;
	m = 1;
	while (*str > 0 && *str <= 32)
		str = str + 1;
	if (*str == '-')
		m = *str++ - 46;
	else if (*str == '+')
		m = 44 - *str++;
	while (*str)
	{
		if (*str > 47 && *str < 58)
			i = i * 10 + *str - 48;
		else if (i || m)
			return (i * m);
		str++;
	}
	return (i * m);
}
