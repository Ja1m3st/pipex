/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimesan <jaimesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 18:19:31 by jaimesan          #+#    #+#             */
/*   Updated: 2024/10/04 13:00:14 by jaimesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_to_hexa(size_t nb, char format)
{
	if (nb >= 16)
	{
		ft_to_hexa(nb / 16, format);
		ft_to_hexa(nb % 16, format);
	}
	else if (nb <= 9)
	{
		ft_putchar(nb + '0');
	}
	else
	{
		if (format == 'x')
			ft_putchar(nb - 10 + 'a');
		else if (format == 'X')
			ft_putchar(nb - 10 + 'A');
	}
}

int	ft_printf_hexa(unsigned int nb, char format)
{
	int	value;

	value = 0;
	if (!nb)
	{
		value += write(1, "0", 1);
		return (value);
	}
	ft_to_hexa(nb, format);
	value += ft_ptrlen(nb);
	return (value);
}
