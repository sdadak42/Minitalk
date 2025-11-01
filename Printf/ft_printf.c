/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdadak <sdadak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:52:39 by sdadak            #+#    #+#             */
/*   Updated: 2025/07/17 12:17:33 by sdadak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_type(va_list arg, int a)
{
	int	count;

	count = 0;
	if (a == 'c')
		count += ft_putchar(va_arg(arg, int));
	else if (a == 's')
		count += ft_putstr(va_arg(arg, char *));
	else if (a == 'i' || a == 'd')
		count += ft_putnbr(va_arg(arg, int));
	else if (a == '%')
		count += ft_putchar('%');
	else if (a == 'p')
		count += ft_putptr(va_arg(arg, unsigned long));
	else if (a == 'u')
		count += ft_putsigned(va_arg(arg, unsigned int));
	else if (a == 'x' || a == 'X')
		count += ft_puthex(va_arg(arg, unsigned int), a);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
			count += ft_type(args, str[++i]);
		else
			count += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
