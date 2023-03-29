/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 23:43:07 by seonggoc          #+#    #+#             */
/*   Updated: 2023/03/30 01:18:28 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libftprintf.h"
#include <unistd.h>
void	ft_rec_hexa(unsigned long long memo, char *hexa)
{
	if (memo / 16 == 0)
	{
		write(1, &hexa[memo % 16], 1);
	}
	else
	{
		ft_rec_hexa(memo / 16, hexa);
		write(1, &hexa[memo % 16], 1);
	}
}

int	ft_puthexa(void *ptr)
{
	char				*hexa;;
	unsigned long long	memo;

	memo = (unsigned long long)ptr;
	hexa = "0123456789abcdef";
	ft_rec_hexa(memo, hexa);
	return (1);
}
