/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimesan <jaimesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 09:54:50 by jaimesan          #+#    #+#             */
/*   Updated: 2024/10/04 12:51:25 by jaimesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_printf(char const *str, ...);
int	ft_putchar(int c);
int	ft_putstr(char	*str);
int	ft_putptr(unsigned long long ptr);
int	ft_putnbr(int nb);
int	ft_putunsiged(unsigned int nb);
int	ft_printf_hexa(unsigned int nb, char format);
int	ft_ptrlen(unsigned long long ptr);

#endif
