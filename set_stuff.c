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

void	set_philos(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_philo)
	{
		data->philos[i].philo_id = i + 1;
		pthread_create(&data->philos[i].thread, NULL, routine, (void *)data);
	}
	i = -1;
	while (++i < data->num_philo)
		pthread_join(data->philos[i].thread, NULL);
}

void	set_forks(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_philo)
	{
		pthread_mutex_init(&data->philos[i].fork_l, NULL);
		pthread_mutex_init(&data->philos[i].fork_r, NULL);
	}
	pthread_mutex_init(&data->time, NULL);
	pthread_mutex_init(&data->eat, NULL);
}

void	*routine(void *data)
{
	t_data	*backup;

	backup = (t_data *)data;
	eat(backup);
	sleep_n_think(SLEEP, *backup);
	sleep_n_think(THINK, *backup);
	return (NULL);
}
