/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 10:59:29 by seonggoc          #+#    #+#             */
/*   Updated: 2023/03/30 16:10:46 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
#include <unistd.h>
#include <stdarg.h>

int	ft_putchar(char c);
int	ft_putnbr_hexa(unsigned long long nbr, int num_case);
unsigned int	ft_putnbr_unsign(unsigned int n);
int	ft_putnbr_sign(int nb);
int	ft_putstr(char *str);
#endif
