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
		data->philos[i].philo_id = i;
/*		pthread_mutex_init(data->philos[i].fork_l, NULL);
		pthread_mutex_init(data->philos[i].fork_r, NULL);*/
		pthread_create(&data->philos[i].thread, NULL, routine, (void *)&data->philos[i]);
	}
	i = -1;
	while (++i < data->num_philo)
	{
		pthread_join(data->philos[i].thread, NULL);
/*		pthread_mutex_destroy(data->philos[i].fork_l);
		pthread_mutex_destroy(data->philos[i].fork_r);*/
	}
}
/*
void	set_forks(t_data *data)
{
	int	i;

	i = -1;
	pthread_mutex_init(data->time);
}
*/
void	*routine(void *data)
{
	t_philo	*backup;

	backup = (t_philo *)data;
//	printf("%d\n", backup->philos->philo_id);
//	eat(backup);
	sleep_n_think(SLEEP, *backup);
	sleep_n_think(THINK, *backup);
	return (NULL);
}
