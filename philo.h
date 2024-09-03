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

# define SLEEP 1
# define THINK 2
# define EAT 3

typedef struct s_philo
{
	pthread_t	thread;
	int		philo_id;
	pthread_mutex_t	*fork_r;
	pthread_mutex_t	*fork_l;
}		t_philo;

typedef struct s_data
{
	t_philo	*philos[200];
	int		num_philo;
	int		time_die;
	int		time_eat;
	int		time_sleep;
	int		num_meals;
}		t_data;

//	main
t_data	set_struct(char **input);

//	utils
int	ft_atoi(char *str);

#endif
