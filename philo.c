/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <davioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:02:21 by davioliv          #+#    #+#             */
/*   Updated: 2024/08/28 18:02:22 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 5)
	{
		printf("Not enough arguments. Try: ./philo <num_philo> <time_die> <time_eat> <time_sleep> [num_meals] (optional)");
		return (0);
	}
	data = set_struct(argv);
	set_program(&data);
	close_program(&data);
	return (0);
}

t_data	set_struct(char **input)
{
	t_data	info;

	info.num_philo = ft_atoi(input[1]);
	info.philos = (t_philo *)malloc(info.num_philo * sizeof(t_philo));
	info.philos->fork_l = malloc((info.num_philo / 2) * sizeof(pthread_mutex_t));
	if (info.num_philo % 2 == 0)
		info.philos->fork_r = malloc((info.num_philo / 2) * sizeof(pthread_mutex_t));
	else
		info.philos->fork_r = malloc((info.num_philo / 2 + 1) * sizeof(pthread_mutex_t));
	info.time_die = ft_atoi(input[2]);
	info.time_eat = ft_atoi(input[3]);
	info.time_sleep = ft_atoi(input[4]);
	if (input[5])
		info.num_meals = ft_atoi(input[5]);
	info.start_time = set_time();
	return (info);
}
