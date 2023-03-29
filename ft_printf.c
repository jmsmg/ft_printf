/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 10:55:31 by seonggoc          #+#    #+#             */
/*   Updated: 2023/03/29 13:51:33 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_check_format(va_list ap, const char *format)
{
	int	sum;

	sum = 0;
	if (*format == 'c')
	{
		ft_putchar(va_arg())
		sum += va_arg(ap, int);
	}
	else if (*format)
	{
		
	}
	return (sum);
}

int	ft_printf(const char *format, ...)
{
	int		sum;
	va_list	ap;

	sum = 0;
	va_start(ap, format);
	if (!format)
	{
		return (-1);
	}
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			sum += ft_check_format(ap, format);
		}
		else
		{
			sum += ft_putchar(*format);
		}
		format++;
	}
	va_end(ap);
	return (i);
}
