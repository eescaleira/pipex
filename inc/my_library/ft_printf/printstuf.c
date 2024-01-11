/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printstuf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 01:05:17 by eescalei          #+#    #+#             */
/*   Updated: 2023/05/24 17:34:17 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, unsigned int	*counter)
{
	char	res;

	if (n == -2147483648)
	{
		ft_putnbr(n / 10, counter);
		*counter += write(1, "8", 1);
	}
	else if (n < 0)
	{
		*counter += write(1, "-", 1);
		ft_putnbr(-n, counter);
	}
	else
	{
		if (n > 9)
			ft_putnbr(n / 10, counter);
		res = (n % 10) + '0';
		*counter += write(1, &res, 1);
	}
}

void	ft_putunbr(unsigned int n, unsigned int *counter)
{
	char	res;

	if (n > 9)
		ft_putunbr(n / 10, counter);
	res = (n % 10) + '0';
	*counter += write(1, &res, 1);
}

void	ft_puthex(unsigned int hex, char flag, unsigned int *counter)
{
	char	*ab;

	if (flag == 'X')
		ab = "ABCDEF";
	else
		ab = "abcdef";
	if (hex / 16 == 0)
	{
		if (hex % 16 < 10)
			ft_putnbr(hex % 16, counter);
		else
			*counter += write(1, &ab[hex % 16 -10], 1);
		return ;
	}
	ft_puthex(hex / 16, flag, counter);
	if (hex % 16 < 10)
		ft_putnbr(hex % 16, counter);
	else
		*counter += write(1, &ab[hex % 16 -10], 1);
}

static void	putp(unsigned long long int hex, unsigned int *counter)
{
	char	*ab;

	ab = "abcdef";
	if (hex / 16 == 0)
	{
		if (hex % 16 < 10)
			ft_putnbr(hex % 16, counter);
		else
			*counter += write(1, &ab[hex % 16 -10], 1);
		return ;
	}
	putp(hex / 16, counter);
	if (hex % 16 < 10)
		ft_putnbr(hex % 16, counter);
	else
		*counter += write(1, &ab[hex % 16 -10], 1);
}

void	ft_puthexp(unsigned long long int hex, unsigned int *counter)
{
	if (!hex)
	{
		*counter += write(1, "(nil)", 5);
		return ;
	}
	*counter += write(1, "0x", 2);
	putp(hex, counter);
}
