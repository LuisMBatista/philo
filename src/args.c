/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:52:02 by lumiguel          #+#    #+#             */
/*   Updated: 2024/11/14 16:20:50 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void	check_args(int ac, char **av)
{
	if( ac != 5 && ac != 6)
	{
		printf("invalid number of arguments");
		exit(1);
	}
	check_av(av);
}


void	check_av(char **av)
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
			printf("Error: No argument can be bigger then a int");
			exit(1);
		}
		if ((i == 1) && (value > 200 || value <1))
		{
			printf("Error: Allowed number of philosofers is between 1 and 200");
			exit(1);
		}
				if ((i != 1) && (value < 1))
		{
			printf("Error: Arguments must be between 1 and INT_MAX");
			exit(1);
		}
	i++;
	}
}

void ll_check(char *av)
{
	int i;
	
	i = 0;
	while (av[i] != '\0')
	{
		if ((av[i] < '0' || av[i] > '9'))
		{
			if (!(i == 0 && av[0] == '-'))
			{
				printf("Error: Arguments must be integers");
				exit(1);
			}
		}
		i++;
	}
	if (ft_strlen(av) > 10)
	{
		printf("Error: No argument can be bigger then a int");
		exit(1);
	}
}
