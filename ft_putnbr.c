/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbuet <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:37:50 by pbuet             #+#    #+#             */
/*   Updated: 2024/10/15 12:18:41 by pbuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putaddr(size_t ptr)
{
	ft_putstr("0x");
	return (ft_putnbr_base(ptr,"0123456789abcdef", 0, 16) + 2);
}

// int upphexa(size_t n, int uplo)
// {
// 	char	hexa[16];
// 	int	i ;
	
// 	i = 0;
// 	while (i < 10)
// 	{
// 		hexa[i] = '0' + i;
// 		i ++ ;
// 	}
// 	while (i < 16)
// 	{
// 		if (uplo == 0)
// 			hexa[i] = 'a' + (i - 10);
// 		else 
// 			hexa[i] = 'A' + (i - 10);
// 		i ++ ;
// 	}
// 	return (ft_putnbr_base(n, hexa, 0));
// }

int	ft_putnbr_base(size_t n, const char *base, int count, size_t len)
{
	int test;
	
	if (n >= len)
		count = ft_putnbr_base(n / len, base, count, len);
	test = ft_putchar(base[n % len]);
	if (test == -1)
		return (-1);
	count += test;
	return (count);
}

// int	unsign(unsigned int n, int count)
// {
// 	if (n >= 10)
// 		count = unsign(n / 10, count);
// 	ft_putchar((n % 10) + '0');
// 	return (count + 1);
// }

int	ft_putnbr(int n, int count)
{
	long	num;
	int test;

	num = n ;
	if (num < 0)
	{
		num *= -1;
		count += ft_putchar('-');
	}
	if (num >= 10)
		count = ft_putnbr(num / 10, count);
	test = ft_putchar((num % 10) + '0');
	if (test == -1)
		return (-1);
	count += test; 
	return (count);
}

