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
		pthread_create(data->philos[i]->thread, NULL, routine, data);
		data->philos[i]->philo_id = i;
		i++;
	}
	i = 0;
	while (i < data->num_philo)
	{
		pthread_join(data->thread[i], NULL);
		i++;
	}
}

void	routine(void *(t_data *)data)
{
	sleep_n_think(1, data, data->philos->philo_id);
	sleep_n_think(2, data, data->philos->philo_id);
	eat(data);
}
