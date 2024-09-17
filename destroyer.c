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
	while (data->philos[i].fork_l || data->philos[i].fork_r)
	{
		if (&data->fork_gen[i])
			pthread_mutex_destroy(&data->fork_gen[i]);
		if (data->philos[i].fork_l)
			pthread_mutex_destroy(data->philos[i].fork_l);
		if (data->philos[i].fork_r)
			pthread_mutex_destroy(data->philos[i].fork_r);
		++i;
	}
	while (&data->fork_gen[i])
	{
		pthread_mutex_destroy(&data->fork_gen[i]);
		++i;
	}
	pthread_mutex_destroy(&data->time);
	pthread_mutex_destroy(&data->eat);
}

static void	free_all(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_philo / 2)
	{
		free(data->philos[i].fork_l);
		free(data->philos[i].fork_r);
	}
	i = -1;
	while (++i < data->num_philo)
	{
		free(&data->philos[i]);
		free(&data->fork_gen[i]);
	}
	if (data->philos[i].fork_l)
		free(data->philos[i].fork_l);
	if (data->philos[i].fork_r)
		free(data->philos[i].fork_r);
}

void	close_program(t_data *data)
{
	mutex_destroyer(data);
	free_all(data);
}
