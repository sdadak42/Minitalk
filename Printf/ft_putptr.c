/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdadak <sdadak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 12:35:35 by sdadak            #+#    #+#             */
/*   Updated: 2025/07/16 13:45:23 by sdadak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(unsigned long ptr)
{
	int	count;

	count = 0;
	if (ptr == 0)
		return (count += write(1, "(nil)", 5));
	count += write(1, "0x", 2);
	count += ft_puthex(ptr, 'x');
	return (count);
}
