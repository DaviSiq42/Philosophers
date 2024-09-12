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

void	mutex_destroyer(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_philo)
	{
		pthread_mutex_destroy(&data->philos[i].fork_l);
		pthread_mutex_destroy(&data->philos[i].fork_r);
	}
	pthread_mutex_destroy(&data->time);
	pthread_mutex_destroy(&data->eat);
}
