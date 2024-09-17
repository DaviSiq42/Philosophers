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

typedef struct s_philo
{
	pthread_t	thread;
	pthread_mutex_t	*fork_r;
	pthread_mutex_t	*fork_l;
	int		philo_id;
	struct s_data *data;
}		t_philo;

typedef struct s_data
{
	t_philo	*philos;
	pthread_mutex_t	*fork_gen;
	pthread_mutex_t	time;
	pthread_mutex_t	eat;
	long long	start_time;
	int		id;
	int		num_philo;
	int		time_die;
	int		time_sleep;
	int		time_eat;
	int		num_meals;
}		t_data;

//	main
t_data	set_struct(char **input);

//	set_stuff
void	set_program(t_data *data);

//	routine
void	*routine(void *data);

//	utils
int	ft_atoi(char *str);
void	messages(t_philo *philo, char *text);
long long	set_time(void);

//	destroyer
void	close_program(t_data *data);

#endif
