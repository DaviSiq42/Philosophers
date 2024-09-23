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
}

static void	free_all(t_data *data)
{
	free(data->fork_gen);
	free(data->philos);
}

void	close_program(t_data *data)
{
	mutex_destroyer(data);
	free_all(data);
}
