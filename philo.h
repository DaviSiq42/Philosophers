/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <davioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:02:45 by davioliv          #+#    #+#             */
/*   Updated: 2024/08/28 18:03:18 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>

# define SLEEP 1
# define THINK 2
# define EAT 3
# define FORK 4

# define SUCCESS 1
# define FAILURE 2

# define OVER 1
# define STILL 0

typedef struct s_philo
{
	pthread_mutex_t	*fork_r;
	pthread_mutex_t	*fork_l;
	pthread_t		thread;
	int				philo_id;
	struct s_data	*data;
}		t_philo;

typedef struct s_data
{
	t_philo			*philos;
	pthread_mutex_t	*fork_gen;
	pthread_mutex_t	check;
	pthread_mutex_t	routine;
	long long		start_time;
	long long		last_meal;
	int				status;
	int				num_meals;
	int				num_philo;
	int				time_die;
	int				time_sleep;
	int				time_eat;
	int				max_meals;
}		t_data;

//	main
t_data		set_struct(char **input);

//	set_stuff
void		set_program(t_data *data);

//	routine
void		*routine(void *data);

//	utils
long long	set_time(void);
void		messages(t_philo *philo, char *text);
void		check_life(t_data *data);
int			ft_atoi(char *str);

//	destroyer
void		close_program(t_data *data);

#endif
