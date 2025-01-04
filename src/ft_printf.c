/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hganet <hganet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:45:37 by hganet            #+#    #+#             */
/*   Updated: 2025/01/04 14:13:23 by hganet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	count_args(const char *format)
{
	int	i;
	int	count;
	
	if (!format)
		return (0);
	count = 0;
	i = 0;
	while (format[i] && format[i + 1])
	{
		if (format[i] == '%'
			&& (format[i + 1] == 'c' || format[i + 1] == 's'
			|| format[i + 1] == 'd' || format[i + 1] == 'i'
			|| format[i + 1] == 'p' || format[i + 1] == 'u'
			|| format[i + 1] == 'x' || format[i + 1] == 'X'
			|| format[i + 1] == '%'))
			{
				count++;
				i++;
			}
		i++;
	}
	return (count);
}

void	process_arg(char format, va_list args)
{
	if (format == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	if (format == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	if (format == 'i' || format == 'd')
		ft_putnbr_fd(va_arg(args, int), 1);
	if (format == 'u')
		ft_putnbr_unsigned_fd(va_arg(args, unsigned int), 1);
	// if (format == 'x' || format == 'X')
	
}

int	ft_printf(const char *format, ...)
{
	int	i;
	int	count;

	count = count_args(format);
	if (count <= 0)
		return (0);
	va_list args;
	va_start(args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] && (format[i + 1] == 'c'
			|| format[i + 1] == 's' || format[i + 1] == 'd'
			|| format[i + 1] == 'i' || format[i + 1] == 'p'
			|| format[i + 1] == 'u' || format[i + 1] == 'x'
			|| format[i + 1] == 'X' || format[i + 1] == '%'))
			{
				process_arg(format[i + 1], args);
				i++;
			}
		else
			write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
