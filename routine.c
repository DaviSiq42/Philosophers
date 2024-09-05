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

void	sleep_n_think(int action, t_data data)
{
	if (action == SLEEP)
	{
		messages(data, "is sleeping");
		usleep(data.time_sleep);
	}
	if (action == THINK)
	{
		messages(data, "is thinking");
		usleep(100);//need to check time philos can stay thinking without dying
	}
}

int	set_time(void)
{
	static long	time;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	time = tv.tv_sec - time;
	if (time == tv.tv_sec)
		return (0);
	return (time);
}

void	eat(t_data *data)
{
	pthread_mutex_init(data->philos->fork_r, NULL);
	pthread_mutex_init(data->philos->fork_l, NULL);
	pthread_mutex_lock(data->philos->fork_r);
	messages(*data, "has taken a fork");
	pthread_mutex_lock(data->philos->fork_l);
	messages(*data, "has taken a fork");
	messages(*data, "is eating");
	usleep(data->time_eat);
	pthread_mutex_unlock(data->philos->fork_r);
	pthread_mutex_unlock(data->philos->fork_l);
	pthread_mutex_destroy(data->philos->fork_r);
	pthread_mutex_destroy(data->philos->fork_l);
}
