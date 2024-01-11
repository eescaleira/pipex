/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 01:01:30 by eescalei          #+#    #+#             */
/*   Updated: 2023/05/24 16:52:57 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
void	ft_putstr(char *s, unsigned int *counter);
void	ft_putnbr(int n, unsigned int	*counter);
void	ft_putunbr(unsigned int n, unsigned int *counter);
void	ft_puthex(unsigned int hex, char flag, unsigned int *counter);
void	ft_puthexp(unsigned int long long hex, unsigned int *counter);

#endif