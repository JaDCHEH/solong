/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:23:18 by cjad              #+#    #+#             */
/*   Updated: 2022/02/13 17:05:34 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

static int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

static void	ft_putnbr(int nbr)
{
	long	n;

	n = (long) nbr;
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar((n % 10) + '0');
}

void	ft_printf(const char *s, ...)
{
	va_list	tmp;
	int		i;

	va_start(tmp, s);
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			ft_putnbr(va_arg(tmp, int));
			i++;
		}
		else
			ft_putchar(s[i]);
		i++;
	}
	va_end(tmp);
}
