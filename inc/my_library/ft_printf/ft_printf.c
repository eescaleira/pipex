/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 23:06:04 by eescalei          #+#    #+#             */
/*   Updated: 2023/05/24 17:34:08 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

void	ft_putstr(char *s, unsigned int *counter)
{
	int	i;

	i = 0;
	if (!s)
	{
		*counter += write(1, "(null)", 6);
		return ;
	}
	while (s[i] != '\0')
	{
		*counter += write(1, &s[i], 1);
		i++;
	}
}

static void	flag_ind(const char strchar, va_list args, unsigned int *result)
{
	int	chars;

	if (strchar == 'c')
	{
		chars = va_arg(args, int);
		*result += write(1, &chars, 1);
	}
	else if (strchar == 's')
		ft_putstr(va_arg(args, char *), result);
	else if (strchar == 'd' || strchar == 'i')
		ft_putnbr(va_arg(args, int), result);
	else if (strchar == 'u')
		ft_putunbr(va_arg(args, unsigned int), result);
	else if (strchar == 'p')
	{
		ft_puthexp(va_arg(args, unsigned long long int), result);
	}
	else if (strchar == 'x' || strchar == 'X')
		ft_puthex(va_arg(args, unsigned int), strchar, result);
}

int	ft_printf(const char *str, ...)
{
	unsigned int	result;
	va_list			args;
	int				i;

	result = 0;
	i = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '%')
				result += write(1, &str[i], 1);
			else
				flag_ind(str[i], args, &result);
		}
		else
			result += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (result);
}

// #include <stdio.h>
// int main (void)
// {
// 	printf ("%p %p", 0, 0);
// 	ft_printf("%p %p", 0, 0);
// 	return 0;
// }