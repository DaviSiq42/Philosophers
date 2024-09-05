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

# define SLEEP 1
# define THINK 2
# define EAT 3
# define FORK 4

typedef struct s_philo
{
	pthread_t	thread;
	int		philo_id;
	pthread_mutex_t	*fork_r;
	pthread_mutex_t	*fork_l;
}		t_philo;

typedef struct s_data
{
	t_philo	*philos;
	int		num_philo;
	int		time_die;
	int		time_eat;
	int		time_sleep;
	int		num_meals;
}		t_data;

//	main
t_data	set_struct(char **input);

//	set_stuff
void	set_philos(t_data *data);
void	*routine(void *data);

//routine
void	sleep_n_think(int action, t_data data);
int	set_time(void);
void	eat(t_data *data);

//	utils
int	ft_atoi(char *str);
void	messages(t_data data, char *text);

#endif
