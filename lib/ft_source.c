/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_source.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 14:06:25 by mkarakul          #+#    #+#             */
/*   Updated: 2023/02/04 14:06:33 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_putchar(char c, int *result)
{
	write(1, &c, 1);
	*result += 1;
}

void	ft_putstr(char *s, int *result)
{
	size_t	i;

	i = 0;
	if (!s)
	{
		ft_putstr("(null)", result);
		result += 6;
		return ;
	}
	while (s[i])
	{
		ft_putchar(s[i], result);
		i++;
	}
}

void	ft_putnbr(int n, int *result)
{
	if (n == -2147483648)
		return (ft_putstr("-2147483648", result));
	if (n < 0)
	{
		ft_putchar('-', result);
		ft_putnbr(-n, result);
	}
	else if (n >= 10)
	{
		ft_putnbr(n / 10, result);
		ft_putchar(n % 10 + '0', result);
	}
	else
		ft_putchar(n + '0', result);
}

void	ft_unsigned(unsigned int i, int *result)
{
	if (i >= 10)
	{
		ft_putnbr(i / 10, result);
		ft_putnbr(i % 10, result);
	}
	else
		ft_putchar(i + '0', result);
}

void	ft_pointer(unsigned long long i, int *result)
{
	char	*base;

	base = "0123456789abcdef";
	if (i >= 16)
	{	
		ft_pointer(i / 16, result);
		ft_pointer(i % 16, result);
	}
	else
		ft_putchar(base[i], result);
}
