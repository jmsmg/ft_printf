/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 01:27:51 by seonggoc          #+#    #+#             */
/*   Updated: 2023/03/30 14:28:39 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

static void	ft_recur(int n, int fd)
{
	if (n <= 9)
	{
		ft_putchar(n + '0', fd);
	}
	else
	{
		ft_recur(n / 10, fd);
		ft_putchar(n % 10 + '0', fd);
	}
}

static int	ft_putnbr(unsigned int n, int fd)
{
	int	i;

	ft_recur(n, fd);
	i = 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	ft_putnbr_fd(int n)
{
	
	ft_putnbr(n, STDOUT_FILENO);
}
