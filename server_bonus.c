/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdadak <sdadak@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 13:28:38 by sdadak            #+#    #+#             */
/*   Updated: 2025/11/01 22:36:53 by sdadak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "Printf/ft_printf.h"

void	ft_signal_process_write(int signal, siginfo_t *info, void *context)
{
	static int	count;
	static char	bit;

	(void)context;
	if (signal == SIGUSR1)
		bit = bit | 1;
	count++;
	if (count == 8)
	{
		if (bit == 0)
		{
			usleep(150);
			kill(info->si_pid, SIGUSR1);
		}
		else
			ft_printf("%c", bit);
		count = 0;
		bit = 0;
	}
	bit = bit << 1;
}

int	main(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = &ft_signal_process_write;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("Pid: %d\n", getpid());
	while (1)
		pause();
	return (0);
}
