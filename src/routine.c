/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:54:47 by lumiguel          #+#    #+#             */
/*   Updated: 2024/11/15 17:57:19 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void routine(t_superv *superv)
{
	int i;

	i = 0;
	while (i < superv->philos[0].num_of_philos)
	{
		pthread_create(&superv->philos[i].thread, NULL, &philo_routine, &superv->philos[i]);
		i++;
	}
	i = 0;
	while (i < superv->philos[0].num_of_philos)
	{
		pthread_join(superv->philos[i].thread, NULL);
		i++;
	}
}

void *philo_routine(void *philo)
{
	t_philo *ph;

	ph = (t_philo *)philo;
	while (1)
	{
		if (philo_eats(ph) == 1)
			return (NULL);
		printf("user1: %d\n", ph->id);
		if (philo_sleeps(ph) == 1)
			return (NULL);
		printf("user2: %d\n", ph->id);
		if (get_current_time_in_ms() - (ph->start_time + ph->last_meal) > ph->time_to_die)
		{
			printf("%ld %d died\n", get_current_time_in_ms() - ph->start_time ,ph->id);
			*ph->dead = 1;
			return (NULL);
		}
	}
}

int philo_sleeps(t_philo *philo)
{
	size_t time;

	time = get_current_time_in_ms();
	if (philo->num_times_to_eat != -1 && philo->meals_eaten >= philo->num_times_to_eat)
		return (0);
	printf("%ld %d is sleeping\n", time - philo->start_time ,philo->id);
	usleep(philo->time_to_sleep * 1000);
	printf("%ld %d is thinking\n", time - philo->start_time ,philo->id);
	return (0);
}

int philo_eats(t_philo *philo)
{
	size_t time;

	time = get_current_time_in_ms();
	if (philo->num_times_to_eat != -1 && philo->meals_eaten >= philo->num_times_to_eat)
		return (0);
	if(philo->superv->dead_flag == 1)
		return (1);
	if (pthread_mutex_trylock(philo->l_fork) == 0 && pthread_mutex_trylock(&philo->r_fork)== 0)
	{
		printf("%ld %d has taken a fork\n", get_current_time_in_ms() - philo->start_time, philo->id);
		printf("%ld %d has taken a fork\n", get_current_time_in_ms() - philo->start_time, philo->id);
		printf("%ld %d is eating\n", time - philo->start_time ,philo->id);
		philo->last_meal = time - philo->start_time;
		philo->meals_eaten++;
		usleep(philo->time_to_eat * 1000);
		pthread_mutex_unlock(&philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
	}
	return (0);
}

