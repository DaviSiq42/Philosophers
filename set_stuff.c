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

	i = 0;
	while (i < data->num_philo)
	{
//		pthread_mutex_init(data->philos[i].fork_l, NULL);
//		pthread_mutex_init(data->philos[i].fork_r, NULL);
//		pthread_create(&data->philos->thread, NULL, routine, (void *)data);
		data->philos->philo_id = i;
		i++;
	}
	i = 0;
	while (i < data->num_philo)
	{
//		pthread_join(data->philos->thread, NULL);
//		pthread_mutex_destroy(data->philos[i].fork_l);
//		pthread_mutex_destroy(data->philos[i].fork_r);
		i++;
	}
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
