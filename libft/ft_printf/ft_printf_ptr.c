/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimesan <jaimesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 10:37:44 by jaimesan          #+#    #+#             */
/*   Updated: 2024/10/04 10:42:37 by jaimesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_ptr_to_hexa(unsigned long long ptr)
{
	if (ptr >= 16)
	{
		ft_ptr_to_hexa(ptr / 16);
		ft_ptr_to_hexa(ptr % 16);
	}
	else if (ptr <= 9)
	{
		ft_putchar(ptr + '0');
	}
	else
	{
		ft_putchar(ptr - 10 + 'a');
	}
}

int	ft_putptr(unsigned long long ptr)
{
	int	value;

	value = 0;
	if (!ptr)
	{
		value += write(1, "(nil)", 5);
		return (value);
	}
	value += write(1, "0x", 2);
	ft_ptr_to_hexa(ptr);
	value += ft_ptrlen(ptr);
	return (value);
}
