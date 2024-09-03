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
	return (0);
}

t_data	set_struct(char **input)
{
	t_data	info;

	info.num_philo = ft_atoi(input[1]);
	info.time_die = ft_atoi(input[2]);
	info.time_eat = ft_atoi(input[3]);
	info.time_sleep = ft_atoi(input[4]);
	if (input[5])
		info.num_meals = ft_atoi(input[5]);
	return (info);
}
