/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <davioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 01:02:50 by davioliv          #+#    #+#             */
/*   Updated: 2024/08/30 01:02:56 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	monitor(t_data *data)
{
	int	i;
	int	finish;

	finish = STILL;
	while (finish == STILL)
	{
		i = -1;
		while (++i < data->num_philo)
		{
			if (finish == STILL && check_life(&data->philos[i]) == OVER)
				finish = OVER;
		}
		usleep(50);
	}
	close_program(data);
}

int	set_philos(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_philo)
	{
		data->philos[i].philo_id = i + 1;
		data->philos[i].last_meal = set_time();
		data->philos[i].num_meals = 0;
		data->philos[i].fork_r = &data->fork_gen[i];
		if (i + 1 == data->num_philo)
			data->philos[i].fork_l = &data->fork_gen[0];
		else
			data->philos[i].fork_l = &data->fork_gen[i + 1];
		data->philos[i].data = data;
		if (pthread_create(&data->philos[i].thread, NULL,
				routine, (void *)&data->philos[i]) != 0)
			return (1);
	}
//	monitor(data);
	return (0);
}

int	set_mutex(t_data *data)
{
	int	i;

	i = -1;
	data->fork_gen = malloc(data->num_philo * sizeof(pthread_mutex_t));
	if (!data->fork_gen)
		return (1);
	while (++i < data->num_philo)
	{
		if (pthread_mutex_init(&data->fork_gen[i], NULL) != 0)
			return (1);
	}
	if (pthread_mutex_init(&data->check, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&data->eat, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&data->monitor, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&data->end, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&data->routine, NULL) != 0)
		return (1);
	return (0);
}

void	set_program(t_data *data)
{
	if (set_mutex(data))
		return ;
	if (set_philos(data))
		return ;
}
