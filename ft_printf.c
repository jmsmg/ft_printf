/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 10:55:31 by seonggoc          #+#    #+#             */
/*   Updated: 2023/03/30 14:29:43 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_check_format(va_list ap, const char *format)
{
	int	sum;

	sum = 0;
	if (*format == 'c')
		sum += ft_putchar(va_arg(ap, int));
	else if (*format == 's')
		sum += ft_putstr_fd(va_arg(ap, void *));
	else if (*format == 'p')
		sum += ft_puthexa(va_arg(ap, void *))
	else if (*format == 'd' || *format == 'i')
		sum += ft_putnbr(va_arg(ap, int));
	else if (*format == 'u')
		va_arg(ap, unsigned int);
	else if (*format == 'x')
		va_arg(ap, unsigned int);
	else if (*format == 'X')
		va_arg(ap, unsigned int);
	else if (*format == '%')
		sum += write(1, "%", 1);
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
