/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takiapo <takiapo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/14 15:11:58 by takiapo           #+#    #+#             */
/*   Updated: 2017/11/29 11:23:16 by takiapo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOS_H
# define PHILOS_H

# include <libc.h> /* time */
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"
# include "struct_philos.h"

# define MAX_LIFE 30
# define EAT_T 5
# define REST_T 10
# define THINK_T 10
# define TIMEOUT 100
# define EAT 1
# define REST 2
# define DEAD -1
# define THINK 3

int					incipit(t_philo **out);
void				team_making(void *hum, t_philo *him);
float				ft_cos(float angle);
float				ft_sin(float angle);
#endif
