/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 10:55:31 by seonggoc          #+#    #+#             */
/*   Updated: 2023/03/30 18:26:29 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_format(va_list ap, const char *format)
{
	int	sum;

	sum = 0;
	if (*format == 'c')
		sum += ft_putchar((char)va_arg(ap, int));
	else if (*format == 's')
		sum += ft_putstr(va_arg(ap, void *));
	else if (*format == 'p')
		sum += ft_putnbr_hexa((unsigned long long)va_arg(ap, void *), 1);
	else if (*format == 'd' || *format == 'i')
		sum += ft_putnbr_sign(va_arg(ap, int));
	else if (*format == 'u')
		sum += ft_putnbr_unsign(va_arg(ap, unsigned int));
	else if (*format == 'x')
		sum += ft_putnbr_hexa(va_arg(ap, unsigned int), 1);
	else if (*format == 'X')
		sum += ft_putnbr_hexa(va_arg(ap, unsigned int), 0);
	else if (*format == '%')
		sum += ft_putchar('%');
	else
		return (-1);
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
	return (sum);
}