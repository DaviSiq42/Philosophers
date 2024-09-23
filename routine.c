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

static int	sleep_n_think(int action, t_philo *philo)
{
	if (check_break(philo) == OVER)
		return (OVER);
	if (action == SLEEP)
	{
		messages(philo, "is sleeping\n");
		usleep(philo->data->time_sleep * 1000);
	}
	if (action == THINK)
	{
		messages(philo, "is thinking\n");
		usleep(philo->data->time_eat * 2 - philo->data->time_sleep);
	}
	return (STILL);
}

int	eat(t_philo *philo)
{
	if (check_break(philo) == OVER)
		return (OVER);
	pthread_mutex_lock(philo->fork_r);
	messages(philo, "has taken a fork\n");
	pthread_mutex_lock(philo->fork_l);
	messages(philo, "has taken a fork\n");
	if (check_break(philo) == OVER)
		return (OVER);
	pthread_mutex_lock(&philo->data->eat);
	messages(philo, "is eating\n");
	philo->last_meal = set_time();
	philo->num_meals++;
	if (philo->num_meals == philo->data->max_meals)
		philo->data->philos_full++;
	pthread_mutex_unlock(&philo->data->eat);
	usleep(philo->data->time_eat * 1000);
	pthread_mutex_unlock(philo->fork_l);
	pthread_mutex_unlock(philo->fork_r);
	return (STILL);
}

void	*routine(void *data)
{
	t_philo	*backup;

	backup = (t_philo *)data;
	while (1)
	{
		if (eat(backup) == OVER)
			break ;
		if (sleep_n_think(SLEEP, backup) == OVER)
			break ;
		if (sleep_n_think(THINK, backup) == OVER)
			break ;
	}
	return (NULL);
}
