/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:16:08 by seonggoc          #+#    #+#             */
/*   Updated: 2023/03/30 20:25:33 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_rec_put_nbr(unsigned long long nbr, char *base, int *i)
{
	*i += 1;
	if (nbr < 16)
	{
		ft_putchar(base[nbr]);
	}
	else
	{
		ft_rec_put_nbr(nbr / 16, base, i);
		ft_putchar(base[nbr % 16]);
	}
	return (*i);
}

int	ft_putnbr_hexa(unsigned long long nbr, const char *format)
{
	int		i;

	i = 0;
	if (*format == 'X')
	{
		return (ft_rec_put_nbr(nbr, "0123456789ABCDEF", &i));
	}
	else if (*format == 'p')
	{
		write(1, "0x", 2);
		i += 2;
	}
	return (ft_rec_put_nbr(nbr, "0123456789abcdef", &i));
}
