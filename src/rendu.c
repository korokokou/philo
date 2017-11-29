/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendu.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takiapo <takiapo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/19 18:15:12 by takiapo           #+#    #+#             */
/*   Updated: 2014/10/19 18:39:35 by takiapo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philos.h"

extern int	g_time;

void		ft_draw_life(t_philo *philo)
{
	float	lp;

	lp = (float)philo->heart / (float)MAX_LIFE;
	if (lp < 0.0f)
		lp = 0.0f;
	if (lp > 0.5)
		glColor3f(1.5f - 3.0f * (lp - 0.5f), 1.0, 0.0f);
	else
		glColor3f(1.0f, lp, 0.0f);
	glBegin(GL_QUADS);
	glVertex2f(-20.0f, -20.0f);
	glVertex2f(-20.0f, -24.0f);
	glVertex2f(-20.0f + 40.0f * lp, -24.0f);
	glVertex2f(-20.0f + 40.0f * lp, -20.0f);
	glEnd();
}

void		ft_draw_chopsticks(t_prgm *prgm, int i)
{
	float	a;

	a = 90.0f + i * (360 / 7);
	glColor3f(0.8f, 0.8f, 0.8f);
	glBegin(GL_LINES);
	if (prgm->philo[i].state == EAT)
	{
		glVertex2f(130.0f * ft_cos(a) + 13.0f, 130.0f * ft_sin(a) + 5.0f);
		glVertex2f(130.0f * ft_cos(a) + 13.0f, 130.0f * ft_sin(a) - 5.0f);
	}
	if (prgm->philo[i].state == EAT || prgm->philo[i].state == THINK)
	{
		glVertex2f(130.0f * ft_cos(a) - 13.0f, 130.0f * ft_sin(a) + 5.0f);
		glVertex2f(130.0f * ft_cos(a) - 13.0f, 130.0f * ft_sin(a) - 5.0f);
	}
	if (prgm->philo[i].state == REST && prgm->philo[i > 0 ? i - 1 : 6].state
			!= EAT)
	{
		a -= 180 / 7;
		glVertex2f(85.0f * ft_cos(a), 85.0f * ft_sin(a));
		glVertex2f(75.0f * ft_cos(a), 75.0f * ft_sin(a));
	}
	glEnd();
}

static void	ft_draw_face(t_prgm *prgm, size_t i)
{
	glColor3f(0.9f, 0.9f, 0.9f);
	if (prgm->philo[i].heart < 0)
	{
		glBegin(GL_TRIANGLES);
		glVertex2f(-9.0f, 6.0f);
		glVertex2f(9.0f, 6.0f);
		glVertex2f(0.0f, 20.0f);
		glEnd();
	}
	glPointSize(3.0f);
	glBegin(GL_POINTS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-5.0f, 2.3f);
	glVertex2f(5.0f, 2.3f);
	glVertex2f(-3.0, 1.2);
	glVertex2f(3.0, 1.2);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-2.0, -4.0);
	glVertex2f(2.0, -4.0);
	glEnd();
}

static void	ft_draw_them(t_prgm *prgm)
{
	size_t	i;
	float	a;

	i = 0;
	glPushMatrix();
	while (i < 7)
	{
		glColor3f(1.0f, 0.76f, 0.67f);
		if (prgm->philo[i].heart <= 0)
			glColor3f(1.0f, 1.0f, 1.0f);
		a = 90.0f + i * (360 / 7);
		glTranslatef(130.0f * ft_cos(a), 130.0f * ft_sin(a), 0.0f);
		gluDisk(prgm->philoq, 0.0, 10.0, 36, 1);
		ft_draw_face(prgm, i);
		pthread_mutex_lock(prgm->philo_mutex + i);
		ft_draw_life(prgm->philo + i);
		glLoadIdentity();
		glTranslatef(400.0f, 300.0f, 0.0f);
		ft_draw_chopsticks(prgm, (int)i);
		pthread_mutex_unlock(prgm->philo_mutex + i);
		glPopMatrix();
		glPushMatrix();
		i++;
	}
	glPopMatrix();
}

void		ft_rendu(t_prgm *prgm)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glColor3f(0.2f, 0.2f, 0.2f);
	glTranslatef(400.0f, 300.0f, 0.0f);
	gluDisk(prgm->table, 0.0, 100.0, 180, 1);
	if (g_time == 0)
		glTranslatef(0.0f, 4.0f, 0.0f);
	ft_draw_them(prgm);
	glFlush();
	glXSwapBuffers(prgm->x, prgm->win);
}
