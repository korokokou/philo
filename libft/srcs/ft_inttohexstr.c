/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inttohexstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbinder <mbinder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 20:46:09 by mbinder           #+#    #+#             */
/*   Updated: 2015/11/29 19:36:30 by mbinder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_inttohexstr(unsigned int num, char *buff)
{
	int		len;
	int		k;
	char	*hex;

	len = 0;
	k = 0;
	hex = ft_strdup("0123456789abcdef");
	while (num != 0)
	{
		buff[len] = hex[num & 0xf];
		len++;
		num >>= 4;
	}
	while (k < len / 2)
	{
		buff[k] ^= buff[len - k - 1];
		buff[len - k - 1] ^= buff[k];
		buff[k] ^= buff[len - k - 1];
		k++;
	}
	buff[len] = '\0';
	free(hex);
	return (len);
}
