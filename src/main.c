/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takiapo <takiapo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/14 14:51:18 by takiapo           #+#    #+#             */
/*   Updated: 2017/11/29 11:22:06 by takiapo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

int					g_time;

void				schedule(t_philo *him)
{
	if (him->state == EAT)
		him->eights = EAT_T;
	if (him->state == REST)
		him->eights = REST_T;
	if (him->state == THINK)
		him->eights = THINK_T;
}

void				change_state(t_philo *left, t_philo *him, t_philo *right)
{
	if (him->state == EAT)
	{
		him->heart = MAX_LIFE;
		him->state = REST;
		pthread_mutex_unlock(&him->chopstick);
		pthread_mutex_unlock(&right->chopstick);
	}
	else if (him->state == THINK && !pthread_mutex_trylock(&right->chopstick))
		him->state = EAT;
	else if (him->state == REST)
	{
		if (left->state == THINK || right->state == THINK
				|| pthread_mutex_trylock(&him->chopstick))
			him->state = REST;
		else if (pthread_mutex_trylock(&right->chopstick))
			him->state = THINK;
		else
			him->state = EAT;
	}
	schedule(him);
}

void				*f(void *seed)
{
	t_trinity		*trio;
	t_philo			*him;

	trio = (t_trinity *)seed;
	him = trio->him;
	while (him && him->state != DEAD && g_time > 0)
	{
		pthread_mutex_lock(&him->life);
		him->eights--;
		if (him->eights == 0)
			change_state(trio->left, him, trio->right);
		if (him->state != EAT)
			him->heart--;
		if (him->heart <= 0)
			him->state = DEAD;
		pthread_mutex_unlock(&him->life);
		usleep(1000000);
	}
	him->it *= -1;
	if (him->state == DEAD)
		him->it = -25;
	return (NULL);
}
void				get_in_the_pgrm(t_philo *him, pthread_t *there,
		t_prgm **prgm)
{
	pthread_mutex_t	*philo_mutex;
	pthread_mutex_t	*wand;
	t_prgm			*temp;
	int				i;

	i = 0;
	temp = malloc(sizeof(t_prgm));
	philo_mutex = malloc(sizeof(pthread_mutex_t) * 7);
	wand = malloc(sizeof(pthread_mutex_t) * 7);
	temp->philo = him;
	temp->thread = there;
	while (i < 7)
	{
		philo_mutex[i] = him[i].life;
		wand[i] = him[i].chopstick;
		i++;
	}
	*prgm = temp;
}

int					main(void)
{
	int				i;
	t_philo			*him;
	t_trinity		duh[7];
	pthread_t		there[7];
	t_prgm			*prgm;

	i = 0;
	if (incipit(&him) != 0)
		return (ft_error("ok", -1));
	team_making(duh, him);
	get_in_the_pgrm(him, there, &prgm);
	while (i < 7)
	{
		if (him[i].it > 0)
			pthread_create(&(there[i]), NULL, f, &(duh[i]));
		i++;
	}
	g_time = TIMEOUT + 1;
	while (g_time--)
		usleep(1000000);
	return (0);
}
