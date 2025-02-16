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

int	think_aux(t_philo *philo)
{
	int	time_think;

	time_think = 0;
	if (philo->data->num_philo % 2 == 0)
	{
		if (philo->data->time_sleep < philo->data->time_eat)
			time_think = philo->data->time_eat - philo->data->time_sleep;
		else
			time_think = 0;
	}
	else
		time_think = philo->data->time_eat * 2 - philo->data->time_sleep;
	return (time_think);
}

int	sleep_n_think(int action, t_philo *philo)
{
	long long	begin;

	begin = set_time();
	if (action == SLEEP)
	{
		messages(philo, "is sleeping\n");
		while (1)
		{
			if (set_time() - begin >= philo->data->time_sleep)
				break ;
			if (check_break(philo) == OVER)
				return (OVER);
			usleep(100);
		}
	}
	if (action == THINK)
	{
		messages(philo, "is thinking\n");
		usleep(think_aux(philo));
	}
	return (STILL);
}

static void	eat_aux(t_philo *philo)
{
	if (philo->philo_id % 2 == 0)
	{
		pthread_mutex_lock(philo->fork_r);
		messages(philo, "has taken a fork\n");
		pthread_mutex_lock(philo->fork_l);
		messages(philo, "has taken a fork\n");
	}
	else
	{
		pthread_mutex_lock(philo->fork_l);
		messages(philo, "has taken a fork\n");
		pthread_mutex_lock(philo->fork_r);
		messages(philo, "has taken a fork\n");
	}
}

int	eat(t_philo *philo)
{
	long long	begin;

	if (check_break(philo) == OVER)
		return (OVER);
	eat_aux(philo);
//	pthread_mutex_lock(&philo->data->eat);
	messages(philo, "is eating\n");
	begin = set_time();
	while (1)
	{
		if (set_time() - begin >= philo->data->time_eat)
			break ;
		if (check_break(philo) == OVER)
			break ;
		usleep(100);
	}
	philo->last_meal = set_time();
//	printf("%d last meal: %lld\n", philo->philo_id, philo->last_meal);
	philo->num_meals++;
	if (philo->num_meals == philo->data->max_meals)
		philo->data->philos_full++;
//	pthread_mutex_unlock(&philo->data->eat);
	pthread_mutex_unlock(philo->fork_l);
	pthread_mutex_unlock(philo->fork_r);
	return (STILL);
}

void	*routine(void *data)
{
	t_philo	*backup;

	backup = (t_philo *)data;
	pthread_mutex_lock(&backup->data->routine);
	pthread_mutex_unlock(&backup->data->routine);
	while (1)
	{
		if (backup->data->num_philo == 1)
		{
			messages(backup, "has taken a fork\n");
			break ;
		}
		if (backup->philo_id % 2 == 0)
			usleep(4000);
		if (eat(backup) == OVER)
			break ;
		if (sleep_n_think(SLEEP, backup) == OVER)
			break ;
		if (sleep_n_think(THINK, backup) == OVER)
			break ;
	}
	return (NULL);
}
