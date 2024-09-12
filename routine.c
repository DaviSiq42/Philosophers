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
		messages(&data, "is sleeping\n");
		usleep(data.time_sleep);
	}
	if (action == THINK)
	{
		messages(&data, "is thinking\n");
		usleep(100);//need to check time philos can stay thinking without dying
	}
}

void	eat(t_data *data)
{
	pthread_mutex_lock(&data->eat);
	pthread_mutex_lock(&data->philos[data->id].fork_r);
	messages(data, "has taken a fork\n");
	pthread_mutex_lock(&data->philos[data->id].fork_l);
	messages(data, "has taken a fork\n");
	messages(data, "is eating\n");
	usleep(data->time_eat);
	pthread_mutex_unlock(&data->philos[data->id].fork_l);
	pthread_mutex_unlock(&data->philos[data->id].fork_r);
	pthread_mutex_unlock(&data->eat);
}
