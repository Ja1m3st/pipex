/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimesan <jaimesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 09:40:04 by jaimesan          #+#    #+#             */
/*   Updated: 2024/10/10 15:43:39 by jaimesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(va_list args, char format)
{
	int	value;

	value = 0;
	if (format == 'c')
		value += ft_putchar(va_arg(args, int));
	else if (format == 's')
		value += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		value += ft_putptr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		value += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		value += ft_putunsiged(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		value += ft_printf_hexa(va_arg(args, unsigned int), format);
	else if (format == '%')
		value += ft_putchar('%');
	return (value);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		i;
	int		value;

	i = 0;
	value = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i] != '\0')
		{
			if (!str[i + 1])
				return (-1);
			value += ft_format(args, str[i + 1]);
			i++;
		}
		else
			value += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (value);
}
