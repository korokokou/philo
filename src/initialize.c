/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takiapo <takiapo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/18 10:50:34 by takiapo           #+#    #+#             */
/*   Updated: 2014/10/19 17:57:45 by takiapo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philos.h"

int					incipit(t_philo **out)
{
	int				i;
	t_philo			*them;

	i = 0;
	if (!(them = malloc(sizeof(t_philo) * 7)))
		return (-1);
	while (i < 7)
	{
		if (pthread_mutex_init(&them[i].chopstick, NULL)
				|| pthread_mutex_init(&them[i].life, NULL))
			return (-1);
		them[i].eights = THINK_T;
		them[i].heart = MAX_LIFE;
		them[i].state = THINK;
		them[i].it = i;
		i++;
	}
	*out = them;
	return (0);
}

void				team_making(void *hum, t_philo *him)
{
	int				i;
	t_trinity		*duh;

	i = 0;
	duh = (t_trinity *)hum;
	while (i < 7)
	{
		if (i == 0)
			duh[i].left = &him[6];
		else
			duh[i].left = &him[i - 1];
		if (i == 6)
			duh[i].right = &him[0];
		else
			duh[i].right = &him[i + 1];
		duh[i].him = &him[i];
		i++;
	}
}
