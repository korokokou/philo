/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takiapo <takiapo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/29 03:31:32 by takiapo           #+#    #+#             */
/*   Updated: 2014/10/17 00:38:39 by takiapo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/libft.h"

int			ft_error(char *str, int ret)
{
	if (str)
		ft_putstr(str);
	else
		return (ret);
	return (ret);
}
