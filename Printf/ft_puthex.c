/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdadak <sdadak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 21:42:33 by sdadak            #+#    #+#             */
/*   Updated: 2025/07/17 12:56:09 by sdadak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long nb, int c)
{
	int		count;
	char	*base;

	count = 0;
	base = "0123456789abcdef";
	if (c == 'X')
		base = "0123456789ABCDEF";
	if (nb > 15)
		count += ft_puthex(nb / 16, c);
	count += ft_putchar(base[nb % 16]);
	return (count);
}
