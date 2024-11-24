/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:52:02 by lumiguel          #+#    #+#             */
/*   Updated: 2024/11/22 14:49:26 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

int	check_args(int ac, char **av)
{
	if( ac != 5 && ac != 6)
	{
		printf("invalid number of arguments\n");
		return(1);
	}
	if (check_av(av) == 1)
		return(1);
	if (one_philo(av) == 1)
		return(1);
	return(0);
}


int	check_av(char **av)
{
	int i;
	long value;

	i = 1;
	while (av[i] != NULL)
	{
		ll_check(av[i]);
		value = atol(av[i]);
		if (value > INT_MAX)
		{
			printf("Error: Arguments must be between 1 and INT_MAX\n");
			return(1);
		}
		if ((i == 1) && (value > INT_MAX || value <1))
		{
			printf("Error: Allowed number of philosofers is between 1 and INT_MAX\n");
			return(1);
		}
				if ((i != 1) && (value < 1))
		{
			printf("Error: Arguments must be between 1 and INT_MAX\n");
			return(1);
		}
	i++;
	}
	return(0);
}

int ll_check(char *av)
{
	int i;
	
	i = 0;
	while (av[i] != '\0')
	{
		if ((av[i] < '0' || av[i] > '9'))
		{
			if (!(i == 0 && av[0] == '-'))
			{
				printf("Error: Arguments must be integers\n");
				return(1);
			}
		}
		i++;
	}
	if (ft_strlen(av) > 10)
	{
		printf("Error: Arguments must be between 1 and INT_MAX\n");
		return(1);
	}
	return(0);
}
int one_philo(char **av)
{
	if (ft_atol(av[1]) == 1)
	{
		printf("0 1 died\n");
		return(1);
	}
	return(0);
}
