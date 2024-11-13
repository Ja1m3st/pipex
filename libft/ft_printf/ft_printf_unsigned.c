/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimesan <jaimesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 17:28:49 by jaimesan          #+#    #+#             */
/*   Updated: 2024/10/04 12:53:08 by jaimesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_fill(char *str, unsigned int num, int index)
{
	while (num > 0)
	{
		str[index] = (num % 10) + 48;
		num /= 10;
		index--;
	}
}

static int	ft_uncount(unsigned int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i = 1;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*ft_unitoa(unsigned int n)
{
	char			*str;
	int				i;
	unsigned int	num;

	i = ft_uncount(n);
	num = 0;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!(str))
		return (NULL);
	str[i--] = '\0';
	if (n == 0)
		str[0] = '0';
	else
		num = n;
	ft_fill(str, num, i);
	return (str);
}

int	ft_putunsiged(unsigned int nb)
{
	int		value;
	char	*num;

	value = 0;
	if (!nb)
		value += write(1, "0", 1);
	else
	{
		num = ft_unitoa(nb);
		value += ft_putstr(num);
		free(num);
	}
	return (value);
}
