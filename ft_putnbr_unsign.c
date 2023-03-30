/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsign.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 01:27:51 by seonggoc          #+#    #+#             */
/*   Updated: 2023/03/30 16:32:27 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_recur_nbr(unsigned int n, int *i)
{
	*i += 1;
	if (n <= 9)
	{
		ft_putchar(n + '0');
	}
	else
	{
		ft_recur_nbr(n / 10, i);
		ft_putchar(n % 10 + '0');
	}
}

unsigned int	ft_putnbr_unsign(unsigned int n)
{
	int	i;

	i = 0;
	ft_recur_nbr(n, &i);
	return (i);
}
