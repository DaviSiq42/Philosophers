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
		printf("Not enough arguments. 5 or 6 arguments required.");
		return (0);
	}
	if (check_arg(argv))
		return (0);
	data = set_struct(argv);
	set_program(&data);
	monitor(&data);
	return (0);
}

t_data	set_struct(char **input)
{
	t_data	info;

	info.num_philo = ft_atoi(input[1]);
	info.philos = (t_philo *)malloc(info.num_philo * sizeof(t_philo));
	info.time_die = ft_atoi(input[2]);
	info.time_eat = ft_atoi(input[3]);
	info.time_sleep = ft_atoi(input[4]);
	if (input[5])
		info.max_meals = ft_atoi(input[5]);
	else
		info.max_meals = -1;
	info.start_time = set_time();
	info.status = STILL;
	info.philos_full = 0;
	return (info);
}

int	check_arg(char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (argv[j])
	{
		i = 0;
		while (argv[j][i])
		{
			if (argv[j][i] < '0' || argv[j][i] > '9' || argv[j][0] == '0')
			{
				printf("Wrong input");
				return (1);
			}
			i++;
		}
		j++;
	}
	return (0);
}
