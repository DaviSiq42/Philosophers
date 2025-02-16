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
	int				num_meals;
	long long		last_meal;
	struct s_data	*data;
}		t_philo;

typedef struct s_data
{
	t_philo			*philos;
	pthread_mutex_t	*fork_gen;
	pthread_mutex_t	check;
	pthread_mutex_t	routine;
	pthread_mutex_t	monitor;
	pthread_mutex_t	end;
	pthread_mutex_t	eat;
	long long		start_time;
	int				status;
	int				philos_full;
	int				num_philo;
	int				time_die;
	int				time_sleep;
	int				time_eat;
	int				max_meals;
}		t_data;

//	main
t_data		set_struct(char **input);
int			check_arg(char **argv);

//	set_stuff
void		set_program(t_data *data);
void		monitor(t_data *data);

//	routine
void		*routine(void *data);

//	utils
long long	set_time(void);
void		messages(t_philo *philo, char *text);
int			check_life(t_philo *philo);
int			ft_atoi(char *str);
int			check_break(t_philo *philo);

//	destroyer
void		close_program(t_data *data);
void		join_threads(t_data *data);

#endif
