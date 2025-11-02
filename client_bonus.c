/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdadak <sdadak@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 13:28:30 by sdadak            #+#    #+#             */
/*   Updated: 2025/11/01 22:41:17 by sdadak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "Printf/ft_printf.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	r;

	i = 0;
	sign = 1;
	r = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		r = (r * 10) + (nptr[i] - '0');
		i++;
	}
	return (r * sign);
}

void	ft_send_str(int pid, char *str)
{
	int	i;
	int	bitcount;

	i = 0;
	bitcount = 0;
	while (str[i])
	{
		bitcount = 7;
		while (bitcount >= 0)
		{
			if ((str[i] >> bitcount) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(200);
			bitcount--;
		}
		i++;
	}
	i = 0;
	while (i++ <= 7)
	{
		kill(pid, SIGUSR2);
		usleep(150);
	}
}

void	return_signal(int signal)
{
	(void)signal;
	ft_printf("Message confirmed by server!\n");
}

int	main(int ac, char **argv)
{
	if (ac != 3)
		return (ft_printf("Wrong number of arguments!\n"), 1);
	signal(SIGUSR1, return_signal);
	ft_send_str(ft_atoi(argv[1]), argv[2]);
	pause();
	return (0);
}
