/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsigned.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdadak <sdadak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 21:26:18 by sdadak            #+#    #+#             */
/*   Updated: 2025/07/16 13:46:24 by sdadak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putsigned(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb > 9)
		count += ft_putsigned(nb / 10);
	count += ft_putchar(nb % 10 + '0');
	return (count);
}
