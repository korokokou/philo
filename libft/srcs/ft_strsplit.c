/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbinder <mbinder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 17:47:46 by mbinder           #+#    #+#             */
/*   Updated: 2015/01/26 17:11:47 by mbinder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

static int	count_words(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i] != '\0')
			count++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (count);
}

static int	count_letters(char *str, char c)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (*(str + i) != c && *(str + i) != '\0')
		i++;
	return (i);
}

static int	ft_copy(char **tab, char *str, char c)
{
	int	i;

	i = 0;
	while (str != NULL && *str != '\0')
	{
		while (*str == c)
			str++;
		if (*str != '\0')
		{
			tab[i] = (char*)ft_memalloc(count_letters(str, c) + 1);
			if (tab[i] == NULL)
				return (-1);
			ft_strncpy(tab[i], str, count_letters(str, c));
			str = str + count_letters(str, c);
			i++;
		}
	}
	tab[i] = NULL;
	return (0);
}

char		**ft_strsplit(const char *s, char c)
{
	char	*str;
	char	**tab;
	size_t	len;

	if (s)
	{
		len = ft_strlen(s) + 1;
		if ((str = (char*)ft_memalloc(sizeof(*str) * (len))) == NULL)
			return (NULL);
		ft_strcpy(str, s);
		if (count_words(str, c) == 0)
		{
			free(str);
			return (NULL);
		}
		if ((tab = (char**)ft_memalloc(sizeof(*tab)
						* (count_words(str, c) + 1))))
			ft_copy(tab, str, c);
		free(str);
		return (tab);
	}
	return (NULL);
}
