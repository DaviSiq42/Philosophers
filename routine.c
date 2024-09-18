/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <davioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 02:30:12 by davioliv          #+#    #+#             */
/*   Updated: 2024/08/31 02:30:13 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	sleep_n_think(int action, t_philo *philo)
{
	if (action == SLEEP)
	{
		messages(philo, "is sleeping\n");
		usleep(philo->data->time_sleep * 1000);
	}
	if (action == THINK)
	{
		messages(philo, "is thinking\n");
		usleep(100);//need to check time philos can stay thinking without dying
	}
}

static void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_r);
	messages(philo, "has taken a fork\n");
	pthread_mutex_lock(philo->fork_l);
	messages(philo, "has taken a fork\n");
	messages(philo, "is eating\n");
	usleep(philo->data->time_eat * 1000);
	check_life(philo->data);
	philo->data->last_meal = set_time() - philo->data->start_time;
	philo->num_meals++;
	pthread_mutex_unlock(philo->fork_l);
	pthread_mutex_unlock(philo->fork_r);
}

void	*routine(void *data)
{
	t_philo	*backup;

	backup = (t_philo *)data;
	pthread_mutex_lock(&backup->data->routine);
/*	while (backup->data->max_meals > 0 && backup->num_meals >= backup->data->max_meals)*/
	{
		eat(backup);
		sleep_n_think(SLEEP, backup);
		sleep_n_think(THINK, backup);
//		check_life(backup->data);
	}
	/*if (backup->data->status == OVER)
		messages(backup, "died\n");*/
	pthread_mutex_unlock(&backup->data->routine);
	return (NULL);
}
