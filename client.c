/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabazyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 12:02:02 by sabazyan          #+#    #+#             */
/*   Updated: 2022/08/16 15:26:14 by sabazyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char	*str)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (str[i] <= 32)
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		num *= 10;
		num += str[i] - '0';
		i++;
	}
	return (num);
}

void	bits(int c, int pid)
{
	int	i;

	i = 8;
	while (i--)
	{
		if (c & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	pid;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		i = -1;
		while (av[2][++i])
			bits(av[2][i], pid);
	}
	return (0);
}
