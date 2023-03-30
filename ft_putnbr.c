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

static void	ft_recur(int nb, int *i)
{
	*i += 1;
	if (nb <= 9)
	{
		ft_putchar(nb + '0');
	}
	else
	{
		ft_recur(nb / 10, i);
		ft_putchar(nb % 10 + '0');
	}
}

int	ft_putnbr_sign(int nb)
{
	int	i;

	i = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		i++;
		nb = -nb;
		ft_recur(nb, &i);
	}
	else
	{
		ft_recur(nb, &i);
	}
	return (i);
}
