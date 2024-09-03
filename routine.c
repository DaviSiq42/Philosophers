/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <davioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 02:30:12 by davioliv          #+#    #+#             */
/*   Updated: 2024/08/31 02:30:13 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleep_n_think(int action, t_data data)
{
	if (action = 1)
	{
		printf("%d %d is sleeping", data.time_sleep, data.philos->philo_id);
		usleep(data.time_sleep);
	}
	if (action = 2)
	{
		printf("%d %d is thinking", 100, data.philos->philo_id);
		usleep(100);//need to check time philos can stay thinking without dying
	}
}

void	eat(t_data *data)
{

