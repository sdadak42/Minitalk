/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdadak <sdadak@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 13:28:38 by sdadak            #+#    #+#             */
/*   Updated: 2025/11/01 22:34:01 by sdadak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "Printf/ft_printf.h"

void	ft_signal_process_write(int signal)
{
	static int	count;
	static char	bit;

	if (signal == SIGUSR1)
		bit = bit | 1;
	count++;
	if (count == 8)
	{
		ft_printf("%c", bit);
		count = 0;
		bit = 0;
	}
	bit = bit << 1;
}

int	main(void)
{
	ft_printf("Pid: %d\n", getpid());
	signal(SIGUSR1, ft_signal_process_write);
	signal(SIGUSR2, ft_signal_process_write);
	while (1)
		pause();
	return (0);
}
