/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <davioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 00:40:27 by davioliv          #+#    #+#             */
/*   Updated: 2024/08/30 00:40:28 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	long	r;

	r = 0;
	while (*str >= '0' && *str <= '9')
	{
		r = r * 10 + (*str - 48);
		str++;
	}
	return (r);
}

void	messages(t_philo *philo, char *text)
{
	long long	time;

	time = set_time() - philo->data->start_time;
	pthread_mutex_lock(&philo->data->check);
	if (text && philo->data->status == STILL)
		printf("%lld %d %s", time, philo->philo_id, text);
	pthread_mutex_unlock(&philo->data->check);
	if (text == NULL)
		printf("%lld all philos are full\n", time);
}

long long	set_time(void)
{
	long long		current_time;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	current_time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (current_time);
}

int	check_life(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->end);
	pthread_mutex_lock(&philo->data->check);
	if (set_time() - philo->last_meal >= philo->data->time_die)
	{
		pthread_mutex_unlock(&philo->data->check);
		messages(philo, "died\n");
		philo->data->status = OVER;
		pthread_mutex_unlock(&philo->data->end);
		return (philo->data->status);
	}
	if (philo->data->max_meals > 0
		&& philo->num_meals >= philo->data->max_meals)
	{
		if (philo->data->num_philo == philo->data->philos_full)
		{
			pthread_mutex_unlock(&philo->data->check);
			philo->data->status = OVER;
			messages(philo, NULL);
			pthread_mutex_unlock(&philo->data->end);
			return (philo->data->status);
		}
	}
	pthread_mutex_unlock(&philo->data->check);
	pthread_mutex_unlock(&philo->data->end);
	return (STILL);
}

int	check_break(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->monitor);
	if (philo->data->status == OVER)
	{
		pthread_mutex_unlock(&philo->data->monitor);
		return (OVER);
	}
	pthread_mutex_unlock(&philo->data->monitor);
	return (STILL);
}
