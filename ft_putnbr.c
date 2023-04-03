/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 21:28:50 by seonggoc          #+#    #+#             */
/*   Updated: 2023/03/30 16:15:34 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_recur(int nb, int *i)
{
	if (*i != -1)
	{
		*i += 1;
	}
	if (nb <= 9)
	{
		if (ft_putchar(nb + '0') == -1)
		{
			*i = -1;
		}
	}
	else
	{
		ft_recur(nb / 10, i);
		if (ft_putchar(nb % 10 + '0') == -1)
		{
			*i = -1;
		}
	}
}

int	ft_putnbr_sign(int nb)
{
	int	i;

	i = 0;
	if (nb == -2147483648)
	{
		return (write(1, "-2147483648", 11));
	}
	else if (nb < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		i++;
		nb = -nb;
	}
	ft_recur(nb, &i);
	return (i);
}

unsigned int	ft_putnbr_unsign(unsigned int n)
{
	int	i;

	i = 0;
	ft_recur(n, &i);
	return (i);
}