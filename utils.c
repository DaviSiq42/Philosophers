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

	pthread_mutex_lock(&philo->data->time);
	time = set_time() - philo->data->start_time;
	printf("%lld %d %s", time, philo->philo_id, text);
	pthread_mutex_unlock(&philo->data->time);
}

long long	set_time(void)
{
	long long	current_time;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	current_time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (current_time);
}
