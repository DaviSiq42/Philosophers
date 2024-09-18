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

static void	set_philos(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_philo)
	{
		data->philos[i].philo_id = i + 1;
		data->last_meal = set_time();
		data->status = STILL;
		data->num_meals = 0;
		data->philos[i].fork_r = &data->fork_gen[i];
		if (i + 1 == data->num_philo)
			data->philos[i].fork_l = &data->fork_gen[0];
		else
			data->philos[i].fork_l = &data->fork_gen[i + 1];
		data->philos[i].data = data;
	}
	i = -1;
	while (++i < data->num_philo)
	{
		if (pthread_create(&data->philos[i].thread, NULL, routine, (void *)&data->philos[i]) != 0)
		{
			close_program(data);
			return ;
		}
	}
	i = -1;
	while (++i < data->num_philo)
		pthread_join(data->philos[i].thread, NULL);
}

static void	set_mutex(t_data *data)
{
	int	i;

	i = -1;
	data->fork_gen = malloc(data->num_philo * sizeof(pthread_mutex_t));
	if (!data->fork_gen)
	{
		close_program(data);
		return ;
	}
	while (++i < data->num_philo)
	{
		if (pthread_mutex_init(&data->fork_gen[i], NULL) != 0)
		{
			close_program(data);
			return ;
		}
	}
	if (pthread_mutex_init(&data->check, NULL) != 0)
	{
		close_program(data);
		return ;
	}
	if (pthread_mutex_init(&data->routine, NULL) != 0)
	{
		close_program(data);
		return ;
	}
}

void	set_program(t_data *data)
{
	set_mutex(data);
	set_philos(data);
}
