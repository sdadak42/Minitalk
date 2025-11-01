/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdadak <sdadak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:51:33 by sdadak            #+#    #+#             */
/*   Updated: 2025/07/16 12:52:48 by sdadak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int a)
{
	int	count;

	count = 0;
	if (a == -2147483648)
		return (count += write(1, "-2147483648", 11));
	if (a < 0)
	{
		count += write(1, "-", 1);
		a = -a;
	}
	if (a > 9)
		count += ft_putnbr(a / 10);
	count += ft_putchar(a % 10 + '0');
	return (count);
}
