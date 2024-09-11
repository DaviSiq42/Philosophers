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

void	sleep_n_think(int action, t_philo data)
{
	if (action == SLEEP)
	{
		messages(&data, "is sleeping\n");
		usleep(data.time_sleep);
	}
	if (action == THINK)
	{
		messages(&data, "is thinking\n");
		usleep(100);//need to check time philos can stay thinking without dying
	}
}

long	set_time(t_philo *data)
{
	static long	prev_time = 0;
	long	timestamp;
	long	current_time;
	struct timeval	tv;

	pthread_mutex_lock(&data->time);
	gettimeofday(&tv, NULL);
	current_time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	timestamp = current_time - prev_time;
	if (prev_time == 0)
	{
		prev_time = current_time;
		pthread_mutex_unlock(&data->time);
		return (0);
	}
	prev_time = current_time;
	pthread_mutex_unlock(&data->time);
	return (timestamp);
}

void	eat(t_philo *data)
{
	pthread_mutex_lock(data->fork_r);
	messages(data, "has taken a fork");
	pthread_mutex_lock(data->fork_l);
	messages(data, "has taken a fork");
	messages(data, "is eating");
	usleep(data->time_eat);
	pthread_mutex_unlock(data->fork_r);
	pthread_mutex_unlock(data->fork_l);
}
