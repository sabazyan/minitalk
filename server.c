/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabazyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 11:59:23 by sabazyan          #+#    #+#             */
/*   Updated: 2022/08/16 15:32:41 by sabazyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	ft_putnum(int num)
{
	if (num > 9)
	{
		ft_putnum(num / 10);
		ft_putnum(num % 10);
	}
	else
		ft_putchar(num + '0');
}

void	ft_printf(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

void	handler(int sig)
{
	static unsigned char	bits;
	static int				flag;

	++flag;
	bits = bits << 1;
	if (sig == SIGUSR1)
		bits = bits | 1;
	if (flag == 8)
	{
		write(1, &bits, 1);
		flag = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_putnum(getpid());
	ft_printf(" is PID\n");
	sa.sa_handler = handler;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
