/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:16:08 by seonggoc          #+#    #+#             */
/*   Updated: 2023/03/30 16:29:54 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_rec_put_nbr(int nbr, char *base, int *i)
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

int	ft_putnbr_hexa(unsigned long long nbr, int num_case)
{
	int		i;

	i = 0;
	if (num_case == 0)
	{
		return (ft_rec_put_nbr(nbr, "0123456789ABCDEF", &i));
	}
	return (ft_rec_put_nbr(nbr, "0123456789abcdef", &i));
}
