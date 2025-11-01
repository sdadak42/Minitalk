/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdadak <sdadak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:40:27 by sdadak            #+#    #+#             */
/*   Updated: 2025/07/16 18:48:59 by sdadak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (!str)
		return (count += write(1, "(null)", 6));
	while (str[i])
		count += write(1, &str[i++], 1);
	return (count);
}
