/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_philos.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takiapo <takiapo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/14 16:03:25 by takiapo           #+#    #+#             */
/*   Updated: 2014/10/19 18:25:34 by takiapo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_PHILOS_H
# define STRUCT_PHILOS_H

# include <X11/Xlib.h>
# include <X11/Xatom.h>
# include <GL/glx.h>
# include <GL/glu.h>
# include <pthread.h>
# include <stddef.h>

typedef struct				s_philo
{
	pthread_mutex_t			life;
	pthread_mutex_t			chopstick;
	int						eights;
	int						heart;
	int						state;
	int						it;
}							t_philo;

typedef struct				s_prgm
{
	t_philo					*philo;
	pthread_mutex_t			*philo_mutex;
	pthread_mutex_t			*wand;
	pthread_t				*thread;
	int						running;
	int						end;
	Display					*x;
	Window					root;
	Window					win;
	XVisualInfo				*vi;
	Colormap				cmap;
	XSetWindowAttributes	swa;
	GLXContext				glc;
	GLUquadric				*table;
	GLUquadric				*philoq;
}							t_prgm;

typedef struct				s_trinity
{
	t_philo					*right;
	t_philo					*him;
	t_philo					*left;
}							t_trinity;
#endif
