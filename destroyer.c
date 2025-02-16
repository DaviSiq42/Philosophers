/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroyer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 12:10:44 by davioliv          #+#    #+#             */
/*   Updated: 2024/09/12 12:10:45 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	mutex_destroyer(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_philo)
	{
		if (&data->fork_gen[i])
			pthread_mutex_destroy(&data->fork_gen[i]);
	}
	pthread_mutex_destroy(&data->check);
	pthread_mutex_destroy(&data->eat);
	pthread_mutex_destroy(&data->routine);
	pthread_mutex_destroy(&data->monitor);
	pthread_mutex_destroy(&data->end);
}

static void	free_all(t_data *data)
{
	free(data->fork_gen);
	free(data->philos);
}

void	join_threads(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_philo)
		pthread_join(data->philos[i].thread, NULL);
}

void	close_program(t_data *data)
{
	join_threads(data);
	mutex_destroyer(data);
	free_all(data);
}
